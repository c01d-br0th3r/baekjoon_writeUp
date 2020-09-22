function solution(numbers) {
    let answer = '';
    const thouNum = numbers.map(num => {
        let strNum = JSON.stringify(num);
        let newStr = '';
        let digit = strNum.length;
        switch (digit) {
            case 1:
                for (let i = 0; i < 4; i++) {
                    newStr += strNum;
                }
                break;
            case 2:
                for (let i = 0; i < 2; i++) {
                    newStr += strNum;
                }
                break;
            case 3:
                newStr += strNum + strNum[0];
                break;
            case 4:
                newStr += strNum;
                break;
        }
        return {parsing: parseInt(newStr), origin: num};
    })
    thouNum.sort((a, b) => b.parsing - a.parsing);
    let newNum = thouNum.map(num => num.origin).join('');
    if (newNum[0] === '0') answer = '0';
    else answer = newNum;
    return answer;
}
