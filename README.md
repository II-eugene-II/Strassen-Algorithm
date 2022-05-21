# Strassen-Algorithm

행렬곱은 굉장히 어려운 행위이다. 인간의 손으로 풀고 있으면 3 x 3 행렬의 곱일지라도 역겹기까지 한다. 풀어도 맞을 것이라는 확신 대신 찝찝함만이 남는다.

조금이라도 더 빨리 계산할 방법은 없는걸까. 


그리고 이러한 알고리즘<sup id="a1">[1](#footnote1)</sup>을 찾았다.

A행렬과 B행렬을 곱하여 C행렬을 만든다고 할때, 각 행렬을 다음과 같은 분할행렬로 나타낸다.

<img src="https://latex.codecogs.com/svg.image?\mathbf{A}&space;=\begin{bmatrix}\mathbf{A}_{1,1}&space;&&space;\mathbf{A}_{1,2}&space;\\\mathbf{A}_{2,1}&space;&&space;\mathbf{A}_{2,2}\end{bmatrix}\mbox&space;{&space;,&space;}\mathbf{B}&space;=\begin{bmatrix}\mathbf{B}_{1,1}&space;&&space;\mathbf{B}_{1,2}&space;\\\mathbf{B}_{2,1}&space;&&space;\mathbf{B}_{2,2}\end{bmatrix}\mbox&space;{&space;,&space;}\mathbf{C}&space;=\begin{bmatrix}\mathbf{C}_{1,1}&space;&&space;\mathbf{C}_{1,2}&space;\\\mathbf{C}_{2,1}&space;&&space;\mathbf{C}_{2,2}\end{bmatrix}" title="https://latex.codecogs.com/svg.image?\mathbf{A} =\begin{bmatrix}\mathbf{A}_{1,1} & \mathbf{A}_{1,2} \\\mathbf{A}_{2,1} & \mathbf{A}_{2,2}\end{bmatrix}\mbox { , }\mathbf{B} =\begin{bmatrix}\mathbf{B}_{1,1} & \mathbf{B}_{1,2} \\\mathbf{B}_{2,1} & \mathbf{B}_{2,2}\end{bmatrix}\mbox { , }\mathbf{C} =\begin{bmatrix}\mathbf{C}_{1,1} & \mathbf{C}_{1,2} \\\mathbf{C}_{2,1} & \mathbf{C}_{2,2}\end{bmatrix}" />

놀랍게도 분할행렬도 단순한 원소처럼 취급할 수 있다고 한다.

행렬곱의 정의에 의해

<img src="https://latex.codecogs.com/svg.image?\mathbf{C}_{1,1}&space;=&space;\mathbf{A}_{1,1}&space;\mathbf{B}_{1,1}&space;&plus;&space;\mathbf{A}_{1,2}&space;\mathbf{B}_{2,1}\\" title="https://latex.codecogs.com/svg.image?\mathbf{C}_{1,1} = \mathbf{A}_{1,1} \mathbf{B}_{1,1} + \mathbf{A}_{1,2} \mathbf{B}_{2,1}\\" />
<img src="https://latex.codecogs.com/svg.image?\mathbf{C}_{1,2}&space;=&space;\mathbf{A}_{1,1}&space;\mathbf{B}_{1,2}&space;&plus;&space;\mathbf{A}_{1,2}&space;\mathbf{B}_{2,2}&space;" title="https://latex.codecogs.com/svg.image?\mathbf{C}_{1,2} = \mathbf{A}_{1,1} \mathbf{B}_{1,2} + \mathbf{A}_{1,2} \mathbf{B}_{2,2} " />
<img src="https://latex.codecogs.com/svg.image?\mathbf{C}_{2,1}&space;=&space;\mathbf{A}_{2,1}&space;\mathbf{B}_{1,1}&space;&plus;&space;\mathbf{A}_{2,2}&space;\mathbf{B}_{2,1}&space;" title="https://latex.codecogs.com/svg.image?\mathbf{C}_{2,1} = \mathbf{A}_{2,1} \mathbf{B}_{1,1} + \mathbf{A}_{2,2} \mathbf{B}_{2,1} " />
<img src="https://latex.codecogs.com/svg.image?\mathbf{C}_{2,2}&space;=&space;\mathbf{A}_{2,1}&space;\mathbf{B}_{1,2}&space;&plus;&space;\mathbf{A}_{2,2}&space;\mathbf{B}_{2,2}&space;" title="https://latex.codecogs.com/svg.image?\mathbf{C}_{2,2} = \mathbf{A}_{2,1} \mathbf{B}_{1,2} + \mathbf{A}_{2,2} \mathbf{B}_{2,2} " />

가 성립한다. 분할 정복은 맞으나, 시간복잡도(얼마나 빠른지를 나타내는 정도)는 똑같다.

여기서 그쳤다면 의미없는 분할&정복이었겠지만, 이 시간복잡도를 <img src="https://latex.codecogs.com/svg.image?\inline&space;n^3" title="https://latex.codecogs.com/svg.image?\inline n^3" /> 에서 <img src="https://latex.codecogs.com/svg.image?\inline&space;n^{log_2&space;7}\approx&space;n^{2.81}" title="https://latex.codecogs.com/svg.image?\inline n^{log_2 7}\approx n^{2.81}" /> 으로 줄이는 알고리즘이 무려 1969년에 나온다.

<img src="https://latex.codecogs.com/svg.image?\inline&space;\mathbf{M}_{1}&space;:=&space;(\mathbf{A}_{1,1}&space;&plus;&space;\mathbf{A}_{2,2})&space;(\mathbf{B}_{1,1}&space;&plus;&space;\mathbf{B}_{2,2})" title="https://latex.codecogs.com/svg.image?\inline \mathbf{M}_{1} := (\mathbf{A}_{1,1} + \mathbf{A}_{2,2}) (\mathbf{B}_{1,1} + \mathbf{B}_{2,2})" />
<img src="https://latex.codecogs.com/svg.image?\inline&space;\mathbf{M}_{2}&space;:=&space;(\mathbf{A}_{2,1}&space;&plus;&space;\mathbf{A}_{2,2})&space;\mathbf{B}_{1,1}" title="https://latex.codecogs.com/svg.image?\inline \mathbf{M}_{2} := (\mathbf{A}_{2,1} + \mathbf{A}_{2,2}) \mathbf{B}_{1,1}" />
<img src="https://latex.codecogs.com/svg.image?\inline&space;\mathbf{M}_{3}&space;:=&space;\mathbf{A}_{1,1}&space;(\mathbf{B}_{1,2}&space;-&space;\mathbf{B}_{2,2})" title="https://latex.codecogs.com/svg.image?\inline \mathbf{M}_{3} := \mathbf{A}_{1,1} (\mathbf{B}_{1,2} - \mathbf{B}_{2,2})" />
<img src="https://latex.codecogs.com/svg.image?\inline&space;\mathbf{M}_{4}&space;:=&space;\mathbf{A}_{2,2}&space;(\mathbf{B}_{2,1}&space;-&space;\mathbf{B}_{1,1})" title="https://latex.codecogs.com/svg.image?\inline \mathbf{M}_{4} := \mathbf{A}_{2,2} (\mathbf{B}_{2,1} - \mathbf{B}_{1,1})" />
<img src="https://latex.codecogs.com/svg.image?\inline&space;\mathbf{M}_{5}&space;:=&space;(\mathbf{A}_{1,1}&space;&plus;&space;\mathbf{A}_{1,2})&space;\mathbf{B}_{2,2}" title="https://latex.codecogs.com/svg.image?\inline \mathbf{M}_{5} := (\mathbf{A}_{1,1} + \mathbf{A}_{1,2}) \mathbf{B}_{2,2}" />
<img src="https://latex.codecogs.com/svg.image?\inline&space;\mathbf{M}_{6}&space;:=&space;(\mathbf{A}_{2,1}&space;-&space;\mathbf{A}_{1,1})&space;(\mathbf{B}_{1,1}&space;&plus;&space;\mathbf{B}_{1,2})" title="https://latex.codecogs.com/svg.image?\inline \mathbf{M}_{6} := (\mathbf{A}_{2,1} - \mathbf{A}_{1,1}) (\mathbf{B}_{1,1} + \mathbf{B}_{1,2})" />
<img src="https://latex.codecogs.com/svg.image?\inline&space;\mathbf{M}_{7}&space;:=&space;(\mathbf{A}_{1,2}&space;-&space;\mathbf{A}_{2,2})&space;(\mathbf{B}_{2,1}&space;&plus;&space;\mathbf{B}_{2,2})" title="https://latex.codecogs.com/svg.image?\inline \mathbf{M}_{7} := (\mathbf{A}_{1,2} - \mathbf{A}_{2,2}) (\mathbf{B}_{2,1} + \mathbf{B}_{2,2})" />

위와 같은 행렬 7개를 정의하면,

<img src="https://latex.codecogs.com/svg.image?\inline&space;\mathbf{C}_{1,1}&space;=&space;\mathbf{M}_{1}&space;&plus;&space;\mathbf{M}_{4}&space;-&space;\mathbf{M}_{5}&space;&plus;&space;\mathbf{M}_{7}" title="https://latex.codecogs.com/svg.image?\inline \mathbf{C}_{1,1} = \mathbf{M}_{1} + \mathbf{M}_{4} - \mathbf{M}_{5} + \mathbf{M}_{7}" />
<img src="https://latex.codecogs.com/svg.image?\inline&space;\mathbf{C}_{1,2}&space;=&space;\mathbf{M}_{3}&space;&plus;&space;\mathbf{M}_{5}" title="https://latex.codecogs.com/svg.image?\inline \mathbf{C}_{1,2} = \mathbf{M}_{3} + \mathbf{M}_{5}" />
<img src="https://latex.codecogs.com/svg.image?\inline&space;\mathbf{C}_{2,1}&space;=&space;\mathbf{M}_{2}&space;&plus;&space;\mathbf{M}_{4}" title="https://latex.codecogs.com/svg.image?\inline \mathbf{C}_{2,1} = \mathbf{M}_{2} + \mathbf{M}_{4}" />
<img src="https://latex.codecogs.com/svg.image?\inline&space;\mathbf{C}_{2,2}&space;=&space;\mathbf{M}_{1}&space;-&space;\mathbf{M}_{2}&space;&plus;&space;\mathbf{M}_{3}&space;&plus;&space;\mathbf{M}_{6}" title="https://latex.codecogs.com/svg.image?\inline \mathbf{C}_{2,2} = \mathbf{M}_{1} - \mathbf{M}_{2} + \mathbf{M}_{3} + \mathbf{M}_{6}" />

라 할 수 있게 되어,

기존의 행렬곱을 8회하고 덧셈을 4회하는 기본 알고리즘에서

행렬곱을 7회하고 덧셈을 18회하는 슈트라센 알고리즘이 탄생한다.

살을 주고 뼈를 취했다는 말이나, 어느 추리만화의 육망성 사건이 떠오르는 기묘한 알고리즘이다.



이를 시작으로 시간복잡도를 점진적으로 <img src="https://latex.codecogs.com/svg.image?\inline&space;n^2" title="https://latex.codecogs.com/svg.image?\inline n^2" /> 까지 낮추는데에 노력하고 있고, 현 시점에서 가장 빠른 시간복잡도는 2020년에 나온 <img src="https://latex.codecogs.com/svg.image?\inline&space;n^{2.3728596}" title="https://latex.codecogs.com/svg.image?\inline n^{2.3728596}" /> 짜리 알고리즘 <sup id="a2">[2](#footnote2)</sup> 이지만...논문을 보면 알 수 있듯이 이 논문을 이해하려면 도대체 선형대수를 어디까지 공부해야 이해할 수 있을까? 라는 의문에 빠진다.

그리고 문득 그런 의문도 든다.

곱셈을 5번만 해서 시간복잡도를 <img src="https://latex.codecogs.com/svg.image?\inline&space;n^{log_2&space;5}\approx&space;=n^{2.321}" title="https://latex.codecogs.com/svg.image?\inline n^{log_2 5}\approx =n^{2.321}" />로 낮출 수 있을까?



><b id="footnote1">1</b> [위키백과 - 슈트라센 알고리즘](https://ko.wikipedia.org/wiki/%EC%8A%88%ED%8A%B8%EB%9D%BC%EC%84%BC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98) [↩](#a1)
>
><b id="footnote2">2</b> [관련 논문](https://arxiv.org/pdf/2010.05846.pdf) [↩](#a2)
