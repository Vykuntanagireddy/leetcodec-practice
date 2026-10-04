bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
signed int temp=x;
long long sum=0;
while(temp!=0){
    int n=(temp%10);
sum=(sum*10)+n;
    temp=temp/10;
}
    return sum == x;
}