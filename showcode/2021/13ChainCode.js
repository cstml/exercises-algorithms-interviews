// Yet another JS solution 
// but done functionally 

let input = "The cat sat on the Ikea mat.";

generateChainCode = function(input) {

    const isLett = x => ((x >= 'a' && x <= `z`) || (x >= 'A' && x <= 'Z'));
    
    const preProcess
          = input.split(" ")
          . map(z => z.split("").map(x => isLett(x) ? x : (` ` + x)))
          . map(x => x.join("")).join(" ");
                    
    const capitalLPos
          = preProcess.split(" ")
          . map(x => x.split("")
                . map(x => x >= 'A' && x <= 'Z'));
  
    const allLowerSC
          = preProcess.toLowerCase()
          .split(" ").map(x => x.split("").sort());
    
    const zip = (x,y) => x.map((_, i) => [x[i],y[i]]);
    
    const capsedSC
          = zip(allLowerSC, capitalLPos)
          . map(([x,y]) => zip(x,y))
          . map(z => z.map(([x,y]) => y ? x.toUpperCase() : x ));
  
    // final manipulation 
    const finalV = capsedSC.map(x=>x.join(""))
                 . reduce((a,x) => isLett(x) 
                                 ? a + ' ' + x 
                                 : a + x);
    
    return finalV;
};

console.log(generateChainCode ("The cat sat on the Ikea mat."));

/*
// I had to destructure the dumb way for the compiler to accept my solution
// So this is what I submitted. But the above works fine in my Node instance.

generateChainCode = function(input) {

    const isLett = x => ((x >= 'a' && x <= `z`) || (x >= 'A' && x <= 'Z'));
    
    const preProcess
          = input.split(" ")
          . map(z => z.split("").map(x => isLett(x) ? x : (` ` + x)))
          . map(x => x.join("")).join(" ");
                    
    const capitalLPos
          = preProcess.split(" ")
          . map(x => x.split("")
                . map(x => x >= 'A' && x <= 'Z'));

    const allLowerSC
          = preProcess.toLowerCase()
          .split(" ").map(x => x.split("").sort());
    
    const zip = (x,y) => x.map((_, i) => [x[i],y[i]]);
    
    const capsedSC
          = zip(allLowerSC, capitalLPos)
          .map(x => zip(x[0], x[1]))
          .map(z => z.map(x => x[1] ? x[0].toUpperCase() : x[0] ));

    finalV = capsedSC.map(x=>x.join("")).reduce((a,x) => isLett(x)
                                                ? a + ' ' + x
                                                : a + x);
    
    return finalV;
};
*/ 
