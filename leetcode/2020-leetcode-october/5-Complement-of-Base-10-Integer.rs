impl Solution {
    pub fn bitwise_complement(n: i32) -> i32 {

        let mut a = 0;
        let mut i = 0;
        let mut nr = n;
        let base:i32 = 2;
        while nr != 0 {
            if nr%2 == 0{
                a += base.pow(i);
            }
            i+=1;
            nr/=2;
        }
        if (a == 0 && i == 0) {
            return 1;
        }
        else { 
            return a;
        }
    }
}
