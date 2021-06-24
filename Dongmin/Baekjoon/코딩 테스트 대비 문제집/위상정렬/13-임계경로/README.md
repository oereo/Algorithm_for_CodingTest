## 1948 임계경로
<br>

### 최단 경로 알고리즘
[SPFA](https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm)  
[Bellman-Ford](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)  
[Dijkstra](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)  

---
### 위상정렬로 구분된 이유
가장 중요한 문제는 메모리 문제다.   
단순히 BFS 방식으로 탐색을 할 경우, 모든 간선을 탐색해야 하기 때문에 visited 체크를 할 수가 없다.  

그렇다면 큐에 쌓이는 노드의 개수는 최대 간선의 개수만큼 쌓일 것이다.    문제에서 V <= 10,000 제약 조건을 줬고,  
DAG에서 간선의 최대 개수는 $$V(V-1) \over 2$$이므로 공간 복잡도가 최악의 경우 $$O(V^2)$$ 까지 차지한다. 직접 정의한 구조체가 최대 6바이트까지 차하므로 50,000,000 * 6bytes = 300MB의 공간을 차지하므로 최대 메모리 제약인 256MB를 넘긴다.  

따라서 간선의 cost는 확인하지만 노드를 직접 큐에 넣는 작업은 이루어져서는 안된다.  
이때, 사용할 수 있는 방법 중 하나가 위상정렬이다. 진입차수가 0이 되지 않는 노드인 경우 간선만 확인을 하고, 큐에 push하는 노드는 진입차수가 0인 노드만이 될 것이다.  
  
---
### 다수의 최장(단) 경로 추적
최장(단) 경로가 하나가 아닌 경우에 그 경로를 추적하는 방식이다.  
memoization 방식으로 그 노드까지의 최장(단) 거리를 기록하고 목적지에서부터 추적한다.  
목적지에서부터 BFS 방식으로 탐색 할때 주어진 간선으로 되돌아가서 caching된 최장(단) 거리와 같은 cost를 갖는다면 그 간선은 최장(단) 경로에 포함되는 간선이다.  
이때도 메모리 문제를 위해서 한번 방문한 노드는 push하지 않되 간선은 확인을 해야 한다.  


<script type="text/javascript" 
src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML">
</script>
