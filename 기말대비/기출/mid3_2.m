score = input("A,B,C,D,F 중 입력하시오\n", 's');
switch (score)
    case 'A'
        fprintf("당신의 점수는 85점 이상이셨군요\n");
    case 'a'
        fprintf("당신의 점수는 85점 이상이셨군요\n");
    case 'B'
        fprintf("당신의 점수는 85점 미만 60점이상이셨군요\n");
    case 'b'
        fprintf("당신의 점수는 85점 미만 60점이상이셨군요\n");
    case 'C'
        fprintf("당신의 점수는 60점 미만 40점이상이셨군요\n");
    case 'c'
        fprintf("당신의 점수는 60점 미만 40점이상이셨군요\n");
    case 'D'
        fprintf("당신의 점수는 40점 미만 0점이상이셨군요\n");
    case 'd'
        fprintf("당신의 점수는 40점 미만 0점이상이셨군요\n");
    case 'F'
        fprintf("열심히 하세요\n");
    case 'f'
        fprintf("열심히 하세요\n");
    otherwise
        fprintf("잘못된 입력입니다\n");
end