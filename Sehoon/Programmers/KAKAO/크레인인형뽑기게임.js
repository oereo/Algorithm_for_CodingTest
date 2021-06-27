function solution(board, moves) {
    var answer = 0;
    let removedCount = 0;
    const basket = [];
    
    moves.forEach(index => {
        const doll = pickTheDoll(board, index-1);
        if(doll){
            if(checkDuplicatedDoll(basket, doll)){
                basket.pop();
                removedCount+=2;
            }
            else{
                basket.push(doll);
            }
        }
    })
    
    return removedCount;
}

function pickTheDoll(board, index){
    for(let i = 0; i<board.length; i++){
        if(board[i][index] !==0){
            const pickedDoll = board[i][index];
            board[i][index] = 0;
            return pickedDoll;
        }
    }
}

function checkDuplicatedDoll(basket, doll){
    if(basket[basket.length-1] === doll)
        return true;
    return false;
}