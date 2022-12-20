#include "Graph.h"

Graph::Graph(int n) {
    EdgeList.resize(n);
}

bool Graph::add(int src, int dest, int weight) {
    if ((src == 0 || dest == 0)) {
        cout << "One of the vertices is 0" << endl;
        return false;
    }
    if ((src > EdgeList.size() || dest > EdgeList.size()) && EdgeList.size() != 0) {
        cout << "Not enough space in graph" << endl;
        return false;
    }
    Edge edge = { src, dest , weight };
    src--;
    EdgeList[src].push_back(edge);
    return true;
}

int Graph::graphSize() {
    return EdgeList.size();
}

void Graph::graphResize(int size) {
    if (size > EdgeList.size()) {
        EdgeList.resize(size);
        return;
    }
    else {
        cout << "Error..." << endl;
    }
}

void Graph::graphClear() {
    EdgeList.clear();
    cout << "Graph has been cleared" << endl;
}

void Graph::printGraph() {
    for (int i = 0; i < EdgeList.size(); i++) {
        for (Edge v : EdgeList[i]) {
            cout << v.src << " -> " << v.dest << " " << "(" << v.weight << ") " << "| ";
        }
        cout << endl;
    }
}

void Graph::BFS(int src)
{
    map<int, bool> checkedNodes; //Проверенные узлы
    queue<int> queue;
    src--;
    queue.push(src);
    while (true)
    {
        int currentNode = queue.front(); //Берем узел
        queue.pop(); //Удаляем из очереди его
        cout << currentNode + 1;  //Вывод узла
        for (int i = 0; i < EdgeList[currentNode].size(); i++) //Пробегаемся по связанным с ним узлами
        {
            if (checkedNodes.count(EdgeList[currentNode][i].dest) == 0) //Если это узел новый, то добавляем его в список проверенных и в очередь
            {
                checkedNodes[EdgeList[currentNode][i].dest] = true;
                queue.push(EdgeList[currentNode][i].dest - 1);
            }
        }
        if (queue.empty()) break;
        else cout << "->";
    }
}

void Graph::printChains() {
    for (int i = 1; i < this->graphSize(); i++) {
        this->BFS(i);
        cout << endl;
    }
}