program primesum
IMPLICIT NONE
INTEGER, DIMENSION(1000001) :: prime_no,jumps  !ALLOCATE SIZE EQUAL TO MAX No. of PRIME NUMBERs WANTED
INTEGER :: i,primes,div,rem,length,sumprime1,lengthprime,limit,sumprime2,backup_length,interval,strlength
REAL :: start,finish,njump,sum_p,backup_sum
call cpu_time(start)
prime_no(1) = 2
prime_no(2) = 3
prime_no(3) = 5
prime_no(4) = 7
jumps(1) = 0
jumps(2) = 0
jumps(3) = 1
jumps(4) = 2
primes=4
njump = jumps(primes) + 1
!sumprime = 17
sum_p = 17
limit=1000000        !!!!!!!!!!!!*************input******************************!!!!!!!!!!!!!!!!!!!!
do while ( sum_p .le. limit )                   
i=2
do while (prime_no(i) .le. SQRT(njump*2 +3) )
 div = njump - jumps(i)
 rem = mod(div,prime_no(i))
 if ( rem == 0 ) then
 njump = njump + 1
 !print*, 'testing jump no.', njump
 i = 2 
 else
 i = i + 1
 end if
end do
primes = primes + 1
prime_no(primes) = njump*2 +3
jumps(primes) = njump
sum_p = sum_p + prime_no(primes)  
!print*,' the new prime nos is', prime_no(primes)
!print*, ' the prime nos. count is',primes
njump = njump + 1
end do
length = primes
backup_sum = sum_p
backup_length = length
if ( sum_p .gt. limit ) then
 sum_p = sum_p - prime_no(primes)
 length = primes - 1
 backup_sum = sum_p
 backup_length = length
end if
if ( mod(sum_p,2.0) == 0 ) then  ! sum_p is even
sum_p = sum_p - prime_no(length) ! sum_p is now odd
length = length-1
endif
!print*, ' the prime no. latest is',prime_no(length),'length is',length
!!! reducing terms from end!!!!
i=2
do while ( prime_no(i) .le. SQRT(sum_p) )
njump = (sum_p-3)/2
div = njump - jumps(i)
rem = mod(div,prime_no(i))
 if ( rem == 0 ) then   ! means sum_p is not prime
 sum_p = sum_p - prime_no(length) - prime_no(length -1)
 length = length - 2
 i = 2
 !! this if will now give the do loop another sum_p and ask it to check whether it is prime, if not this will continue
 else
 i = i + 1 ! check for all the prime nos. till square root of sum_p
 end if
end do
!!! this loop will be exit when some prime no. is found!!!
sumprime1 = sum_p       !!! store the prime no. obtained after subtracting terms out of sum_p from end
lengthprime = length   !!! store the length i.e total number of consecutive primes added to obtain a prime
!print*,' the prime no. which is sum of',lengthprime,'consecutive primes is',sumprime1
!!! reducing terms from start!!!!
sum_p = backup_sum 
length = backup_length
strlength = 1
if ( mod(sum_p,2.0) == 0 ) then  ! sum_p is even
sum_p = sum_p - prime_no(strlength) - prime_no(strlength+1)! sum_p is now odd, since first prime no is 2 hence we need to subtract one more    
strlength = strlength+2                                   ! term from start to make sum_p odd number
endif
i=2
do while ( prime_no(i) .le. SQRT(sum_p) )
njump = (sum_p-3)/2
div = njump - jumps(i)
rem = mod(div,prime_no(i))
 if ( rem == 0 ) then   ! means sum_p is not prime
 sum_p = sum_p - prime_no(strlength) 
 strlength = strlength + 1
 interval = length - strlength + 1
    if ( mod(sum_p,2.0) == 0 ) then   ! sum_p is even
    sum_p = sum_p - prime_no(strlength)  !! make it odd
    strlength = strlength + 1
    interval = length - strlength + 1
    endif 
 !print*, ' the new sum is',sum_p,'length is',interval
 i = 2
 !! this if will now give the do loop another sum_p and ask it to check whether it is prime, if not this will continue
 else
 i = i + 1 ! check for all the prime nos. till square root of sum_p
 end if
end do
sumprime2 = sum_p
!print*, ' the latest prime nos. is',prime_no(primes)
if (lengthprime .gt. interval ) then 
  print*,sumprime1
  !print*,' starting from 2'
else
  print*,sumprime2
  !print*,'starting from',prime_no(strlength-1)
endif
call cpu_time(finish)
print '(f6.3," seconds.")',finish-start
end program primesum

