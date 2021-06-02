# my-realestate-Dapp
## simple real-estate Dapp (solidity)
- 출처 : 인프런(블록체인 이더리움 부동산 댑(Dapp) 만들기 – 기본편)
- Dapp의 프론트엔드부터 서버까지의 동작과정을 이해하기 위한 심플한 부동한 dApp 구현 Tutorial 진행
- ganache, truffle framework를 사용해 solidity와 프론트엔드(jquery), metamask를 연동하여 화면에서 부동산 매입후 매입한 계정정보를 이벤트 메시징 하는 부분까지 구현.  



# Tech Stack

- metamask 설치
- solidiy 설치
- truffle 설치 !!4.1.15 버전으로 설치할 것!!
- ganache 설치
- npm 설치
- jQurey 설치



# npm install 명령어로 패키지 설치

1. $ cd my-real-estate

![folder](https://user-images.githubusercontent.com/73675540/120419959-5c8e2280-c39e-11eb-9c87-a4d93e301653.png)

2. $ npm install



# 가나슈 && 메타마스크

가나슈의 MNEMONIC 구문을 통해 메타마스크 연동 (Localhost 8545 연결)

![meta0](https://user-images.githubusercontent.com/73675540/120419967-61eb6d00-c39e-11eb-9d9c-583696c1f266.png)
![meta](https://user-images.githubusercontent.com/73675540/120419973-644dc700-c39e-11eb-953b-9ae7ff7950cd.png)



# 실행하기

1. $ cd my-real-estate
2. 	컴파일하여 네트워크와 가나슈 연결? (가스 감소)
- $ truffle migrate --compile-all --reset --network ganache
3. frontend 실행
- $ npm run dev

![front](https://user-images.githubusercontent.com/73675540/120420003-7596d380-c39e-11eb-9c36-08ee8900d0d9.png)

4. vscode로 app.js 실행

![code](https://user-images.githubusercontent.com/73675540/120420022-7c254b00-c39e-11eb-9f61-34d7906df221.png)

   *메타마스크와 계정 연동 시*
    web3.eth.getAccounts(function(error, accounts) {    =>   주석처리
	ethereum.enable().then(function (accounts) {        =>   사용
	*메타마스크와 계정 연동 시*
    ethereum.enable().then(function (accounts) {        =>   주석처리
	web3.eth.getAccounts(function(error, accounts) {    =>   사용



# 구현 화면

![trade3](https://user-images.githubusercontent.com/73675540/120420043-821b2c00-c39e-11eb-9948-d5aec1aa941e.png)
![trade4](https://user-images.githubusercontent.com/73675540/120420055-88110d00-c39e-11eb-9941-19bc096afad7.png)
![trade5](https://user-images.githubusercontent.com/73675540/120420077-90694800-c39e-11eb-802c-33154ea73bf7.png)

