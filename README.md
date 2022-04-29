# Strassen-Formula

행렬곱은 굉장히 어려운 행위이다. 인간의 손으로 풀고 있으면 3 x 3 행렬의 곱일지라도 역겹기까지 한다. 풀어도 맞을 것이라는 확신 대신 찝찝함만이 남는다.

조금이라도 더 빨리 계산할 방법은 없는걸까. 


그리고 이러한 알고리즘<sup id="a1">[1](#footnote1)</sup>을 찾았다.

A행렬과 B행렬을 곱하여 C행렬을 만든다고 할때, 각 행렬을 다음과 같은 분할행렬로 나타낸다.

<img src="https://latex.codecogs.com/svg.image?\mathbf{A}&space;=\begin{bmatrix}\mathbf{A}_{1,1}&space;&&space;\mathbf{A}_{1,2}&space;\\\mathbf{A}_{2,1}&space;&&space;\mathbf{A}_{2,2}\end{bmatrix}\mbox&space;{&space;,&space;}\mathbf{B}&space;=\begin{bmatrix}\mathbf{B}_{1,1}&space;&&space;\mathbf{B}_{1,2}&space;\\\mathbf{B}_{2,1}&space;&&space;\mathbf{B}_{2,2}\end{bmatrix}\mbox&space;{&space;,&space;}\mathbf{C}&space;=\begin{bmatrix}\mathbf{C}_{1,1}&space;&&space;\mathbf{C}_{1,2}&space;\\\mathbf{C}_{2,1}&space;&&space;\mathbf{C}_{2,2}\end{bmatrix}" title="https://latex.codecogs.com/svg.image?\mathbf{A} =\begin{bmatrix}\mathbf{A}_{1,1} & \mathbf{A}_{1,2} \\\mathbf{A}_{2,1} & \mathbf{A}_{2,2}\end{bmatrix}\mbox { , }\mathbf{B} =\begin{bmatrix}\mathbf{B}_{1,1} & \mathbf{B}_{1,2} \\\mathbf{B}_{2,1} & \mathbf{B}_{2,2}\end{bmatrix}\mbox { , }\mathbf{C} =\begin{bmatrix}\mathbf{C}_{1,1} & \mathbf{C}_{1,2} \\\mathbf{C}_{2,1} & \mathbf{C}_{2,2}\end{bmatrix}" />











><b id="footnote1">1</b> [위키백과 - 슈트라센 알고리즘](https://ko.wikipedia.org/wiki/%EC%8A%88%ED%8A%B8%EB%9D%BC%EC%84%BC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98) [↩](#a1)
