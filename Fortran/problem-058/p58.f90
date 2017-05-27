program prime
IMPLICIT NONE
INTEGER, DIMENSION(5001) :: prime_no,jumps  !ALLOCATE SIZE EQUAL TO MAX PRIME NUMBER WANTED
INTEGER :: i,primes,div,rem,layer,limit,dia_ele,spi_pri,j,ele,ratio,f_ratio,njump
real :: start, finish
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
ele = 9
!njump = jumps(primes) + 1
f_ratio = 10
layer=1
limit=(2*layer+1)**2
dia_ele = 5
spi_pri = 3 
ratio = spi_pri*100/dia_ele

do                     !! blind loop
i=2

do while (prime_no(i) .le. SQRT(real(ele)) )  !! Checking whether current diagonal element is prime

   do while (prime_no(primes) .lt. SQRT(real(ele)) )   !! indicates that no. of primes in the array(upto square root of exiting element) needs to be increased
     !print*,'Prime no. array needs to be updated for element', ele  !!<---------------check 
     njump = jumps(primes) + 1 
     j=2
     do while (prime_no(j) .le. SQRT(real(njump)*2 +3) )  !! checking for new prime nos.
      div = njump - jumps(j)
      rem = mod(div,prime_no(j))
       if ( rem == 0 ) then
         njump = njump + 1
        !print*, 'testing jump no.', njump
        j = 2 
       else
        j = j + 1
       end if
      end do
     primes = primes + 1            ! new prime no. found 
     prime_no(primes) = njump*2 +3  ! storing new prime no.
     !print*,'new prime no. found',prime_no(primes)
     jumps(primes) = njump          !storing new jump correspinding to prime no. which was found
   end do
  !! Now number of primes in the array are sufficient to check whether current diagonal element (ele) is prime
     
   if (ele == limit ) then
   ratio = spi_pri*100/dia_ele
   !print*,'element is',ele
   !print*,'for layer' ,layer,'spiral primes are ',spi_pri
   !print*,'for layer' ,layer,'diagonal elements are ',dia_ele 
   !print*,'for layer' ,layer,'ratio is ',ratio
   if ( ratio .lt. f_ratio) then               !!!<----------------------TERMINATING CONDITION
     !print*,'ratio less than f_ratio'
    print*,2*layer+1
     exit
   end if 
   !print*,'skipping',ele,'layer',layer
   layer = layer + 1  !proceeding to next layer
   limit=(2*layer+1)**2
   dia_ele = dia_ele + 4
   ele = ele + (2*layer)   ! next diagonal element to check for prime without checking current element as it will be perfect square
   end if  

      njump = (ele - 3)/2
      div = njump - jumps(i)
      rem = mod(div,prime_no(i))
       if ( rem == 0 ) then                 !! Indicates that current element is not prime
            if (ele == limit ) then
              ratio = spi_pri*100/dia_ele
              !print*,'element is',ele
              !print*,'for layer' ,layer,'spiral primes are ',spi_pri
             !print*,'for layer' ,layer,'diagonal elements are ',dia_ele
              !print*,'for layer' ,layer,'ratio is ',ratio
                !print*,'skipping',ele,'layer',layer
                if ( ratio .lt. f_ratio) then               !!!<----------------------TERMINATING CONDITION
                 ! print*,'ratio less than f_ratio'
                print*,2*layer+1
                  exit
                end if 
              layer = layer + 1  !proceeding to next layer
              limit=(2*layer+1)**2
              dia_ele = dia_ele + 4
              ele = ele + (2*layer)   ! next diagonal element to check for prime without cchecking current element as it will be perfect square
             else
             ele = ele + (2*layer)   ! next diagonal element in the same layer
             end if
        i = 2                        !  reset the counter to check the prime from array start
       else
        i = i + 1
       end if
end do 
!!!!Coming out of this loop indicates that the current diagonal element is prime
if ( ratio .lt. f_ratio) then               !!!<----------------------TERMINATING CONDITION
  !print*,'ratio less than f_ratio'
  exit
end if
spi_pri = spi_pri + 1
!print*,'spiral prime is ' ,ele
ele = ele + (2*layer)

end do            !! blind loop ends

call cpu_time(finish)
!print*, ' the prime nos. count is',primes
!print*,' the new prime nos is', prime_no(primes)
print '("Time = ",f6.3," seconds.")',finish-start
end program prime

