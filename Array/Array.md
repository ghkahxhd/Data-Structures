# Array
***
## 1. ADT
### 1.1. Objects
> index의 각 값에 대하여 집합 item에 속한 한 값이 존재하는 <index, value> 쌍의 집합.
index는 1차원 또는 다차원의 유한 순서 집합이다. 예를 들면, 1차원의 경우 {0, ..., n-1}과 2차원 배열 {(0, 0), (0, 1), (1, 0), (1, 1)} 등이다.

### 1.2. Functions
모든 A \in Array, i \in index, x \in item, j,size \in integer

* **Array Create(j, list) ::=**  
        return j차원의 배열.  
        여기서 list는 i번째 원소가 i번째 차원의 크기인 j-tuple이며 item들은 정의되지 않았음.


* **Item Retrive(A, i) ::=**  
        if (i \in index)
            return 배열 A의 인덱스 i값과 관련된 항목.
        else
            return 에러.

* **Array Store(A, i, x) ::=**  
        if (i \in index)
            return 새로운 쌍 <i, x>가 삽입된 배열 A.
        else
            return 에러.
