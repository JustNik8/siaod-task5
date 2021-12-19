#include <iostream>
#include "Graph.h"
#include <string.h>

using namespace std;

Graph* initGraphFromConsole();
Graph* getDefaultGraph1();
Graph* getDefaultGraph2();
Graph* getDefaultGraph3();
Graph* getDefaultGraph4();
Graph* getDefaultGraph5();
Graph* getDefaultGraph6();

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Граф по умолчанию?(y/n): ";
    char graphDecision;
    cin >> graphDecision;

    Graph* graph = new Graph(0);
    if (graphDecision == 'y') {
        cout << "Какой граф по счету? (1-6): ";
        int graphNumber;
        cin >> graphNumber;
        if (graphNumber == 1) {
            graph = getDefaultGraph1();
        }
        else if (graphNumber == 2) {
            graph = getDefaultGraph2();
        }
        else if (graphNumber == 3) {
            graph = getDefaultGraph3();
        }
        else if (graphNumber == 4) {
            graph = getDefaultGraph4();
        }
        else if (graphNumber == 5) {
            graph = getDefaultGraph5();
        }
        else {
            graph = getDefaultGraph6();
        }

    }
    else {
        graph = initGraphFromConsole();
    }

    //Вывод матрицы смежности и листа смежности
    cout << "\tГраф\n\n";
    graph->printMatrix();
    cout << "\n";
    graph->printGraph();
    cout << "\n\n";

    //Поиск остовного дерева и его вывод (Задание 2 и 3)
    Tree* spanningTree = graph->spanningTree(1);
    cout << "Остовное дерево, построеное алгоритмом поиска в ширину:\n";
    spanningTree->print();

    //Вывод глубины графа (задание 1)
    cout << "Введите вершину, от которой считать глубину: ";
    int root;
    cin >> root;
    cout << "\nГлубина графа: ";
    cout << graph->depth(root);
    
}

Graph* initGraphFromConsole() {
    int vertexAmount;
    cout << "Введите количество вершин графа: ";
    cin >> vertexAmount;

    Graph* graph = new Graph(vertexAmount);

    int num1 = 0, num2 = 0, weight = 0;

    cout << "Ввод номер1 номер2 вес(если нет веса, то писать 0)\n";
    cout << "Введите -1 в поле номер1 для завершения\n";
    while (num1 != -1) {
        cin >> num1;
        if (num1 == -1) break;

        cin >> num2 >> weight;
        if (graph->addEdge(num1, num2, (weight == NULL) ? 1 : weight)) {
            cout << "Успешно добавлено\n";
        }
        else {
            cout << "Не удалось добавить\n";
        }

    }

    return graph;
}

Graph* getDefaultGraph1() {
    int vertexAmount = 5;

    Graph* graph = new Graph(vertexAmount);

    graph->addEdge(1, 2, 1);
    graph->addEdge(1, 5, 10);
    graph->addEdge(1, 3, 2);
    graph->addEdge(2, 5, 6);
    graph->addEdge(3, 5, 5);
    graph->addEdge(2, 4, 3);
    graph->addEdge(5, 4, 11);
    graph->addEdge(3, 4, 4);

    return graph;
}

Graph* getDefaultGraph2()
{
    int vertexAmount = 6;

    Graph* graph = new Graph(vertexAmount);

    graph->addUndirectedEdge(1, 2, 7);
    graph->addUndirectedEdge(1, 4, 2);
    graph->addUndirectedEdge(2, 4, 2);
    graph->addUndirectedEdge(1, 6, 4);
    graph->addUndirectedEdge(4, 6, 1);
    graph->addUndirectedEdge(6, 5, 8);
    graph->addUndirectedEdge(4, 5, 6);
    graph->addUndirectedEdge(3, 5, 3);
    graph->addUndirectedEdge(2, 3, 1);
    graph->addUndirectedEdge(4, 3, 2);

    return graph;
}

Graph* getDefaultGraph3()
{
    int vertexAmount = 7;

    Graph* graph = new Graph(vertexAmount);

    graph->addEdge(1, 2, 20);
    graph->addEdge(2, 3, 15);
    graph->addEdge(3, 4, 3);
    graph->addEdge(4, 5, 17);
    graph->addEdge(5, 6, 28);
    graph->addEdge(6, 1, 23);
    graph->addEdge(7, 2, 4);
    graph->addEdge(7, 3, 9);
    graph->addEdge(7, 4, 16);
    graph->addEdge(7, 5, 25);
    graph->addEdge(7, 6, 36);
    graph->addEdge(7, 1, 1);

    return graph;
}

Graph* getDefaultGraph4()
{
    int vertexAmount = 6;

    Graph* graph = new Graph(vertexAmount);

    graph->addEdge(1, 3, 6);
    graph->addEdge(3, 6, 5);
    graph->addEdge(6, 5, 4);
    graph->addEdge(5, 2, 8);
    graph->addEdge(2, 1, 2);
    graph->addEdge(4, 1, 4);
    graph->addEdge(4, 3, 8);
    graph->addEdge(4, 6, 8);
    graph->addEdge(4, 5, 2);
    graph->addEdge(4, 2, 7);

    return graph;
}

Graph* getDefaultGraph5() {
    int vertexAmount = 6;

    Graph* graph = new Graph(vertexAmount);

    graph->addEdge(1, 2, 2);
    graph->addEdge(1, 4, 4);
    graph->addEdge(1, 3, 4);
    graph->addEdge(2, 4, 4);
    graph->addEdge(2, 5, 3);
    graph->addEdge(3, 6, 7);
    graph->addEdge(4, 5, 6);
    graph->addEdge(4, 6, 2);
    graph->addEdge(5, 6, 2);

    return graph;
}

Graph* getDefaultGraph6()
{
    int vertexAmount = 6;

    Graph* graph = new Graph(vertexAmount);

    graph->addEdge(1, 2, 8);
    graph->addEdge(1, 3, 4);
    graph->addEdge(2, 4, 6);
    graph->addEdge(2, 5, 3);
    graph->addEdge(3, 4, 2);
    graph->addEdge(3, 2, 3);
    graph->addEdge(3, 6, 10);
    graph->addEdge(4, 6, 1);
    graph->addEdge(4, 5, 3);
    graph->addEdge(5, 6, 4);

    return graph;
}


