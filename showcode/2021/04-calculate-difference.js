/*
Function that takes a list: [1,4,5,0]  and calculates the largest number - the smallest number
ex:
calculateDifference ([1,4,5,0]) = 5410 - 1045
                                = 4365
*/
calculateDifference = function(input) {
    const comb   = (c,x) => x + c*10;
    const large  = input.sort().reverse().reduce(comb);
    const smallT = input.sort().filter(x => x !== 0);
    const zeroes = [0] * (input.length - smallT.length); 
    const small  = Array.prototype.concat(smallT[0], zeroes).concat(smallT.slice(1)).reduce(comb);    
    return large - small;
};
