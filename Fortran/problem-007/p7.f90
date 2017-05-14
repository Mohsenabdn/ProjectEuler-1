program prime
IMPLICIT NONE
INTEGER, DIMENSION(10001) :: prime_no,jumps  !ALLOCATE SIZE EQUAL TO MAX PRIME NUMBER WANTED
INTEGER :: i,primes,div,rem
real :: start, finish,njump
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
do while ( primes .le. 10000 )                  ! IF YOU WANT (N+1)TH PRIME NO. THEN TYPE N AFTER '.le' 
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
!print*,' the new prime nos is', prime_no(primes)
!print*, ' the prime nos. count is',primes
njump = njump + 1
end do
call cpu_time(finish)
!print*, ' the prime nos. count is',primes
print*,prime_no(primes)
print '(f6.3," seconds.")',finish-start
end program prime

