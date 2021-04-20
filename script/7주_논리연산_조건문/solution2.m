clear
clc
%1
data = input('A B C D F 중 입력하시오 : ', 's');
if data == 'A'
    fprintf('85 이상입니다.\n')
elseif data == 'B'
    fprintf('85 미만 60 이상입니다.\n')
elseif data == 'C'
    fprintf('60 미만 40 이상입니다.\n')
elseif data == 'D'
    fprintf('40 미만 0 이상입니다.\n')
else
    fprintf('열심히하세요\n')
end
%1 - switch 
data = input('A B C D F 중 입력하시오 : ', 's');
if (data == 'A' || data == 'B' || data == 'C' || data == 'D' || data == 'F')
    switch data
        case 'A'
            fprintf('85 이상입니다.\n')
        case 'B'
            fprintf('85 미만 60 이상입니다.\n')
        case 'C'
            fprintf('60 미만 40 이상입니다.\n')
        case 'D'
            fprintf('40 미만 0 이상입니다.\n')
        otherwise
            fprintf('열심히하세요\n')
    end
else
    fprintf('잘못된 입력입니다.\n')
end
    
                
                