function solution(nums) {
    var answer = 0;
    var numsLength = nums.length/2;
    console.log(numsLength);
    
    const uniqueNums = nums.filter((v, index) => {return nums.indexOf(v) === index;});
    console.log(uniqueNums);
    const uniqueLength = uniqueNums.length;
    
    if(uniqueLength >= numsLength){
        return numsLength;
    }
    else{
        return uniqueLength;
    }
    
}