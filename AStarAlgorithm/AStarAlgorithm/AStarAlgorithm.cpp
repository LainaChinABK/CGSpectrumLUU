// AStarAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

// function declarations
int AStar(std::map<char, Node> graph, char start, char goal);
int Index(char c, std::vector<char> v);

struct Node {
    char label;
    int cost = 0;
    std::vector<std::pair<Node, int>> successors;
};

int main()
{
    // create nodes
    Node a;
    Node b;
    Node c;
    Node d;

    a.label = 'a';
    b.label = 'b';
    c.label = 'c';
    d.label = 'd';

    a.successors.push_back(std::make_pair(b, 5));
    b.successors.push_back(std::make_pair(c, 1));
    a.successors.push_back(std::make_pair(d, 7));
    c.successors.push_back(std::make_pair(d, 1));

    std::map<char, Node> graph = { {'a', a}, {'b', b}, {'c', c}, {'d', d} };
}

// returns cost of cheapest path or -1 if path does not exist
int AStar(std::map<char, Node> graph, char start, char goal)
{
    Node cur, temp;
    int sCost = 0;

    std::vector<char> open = { start };
    std::vector<char> closed;

    while (!open.empty())
    {
        cur = graph[open.back()];
        open.pop_back();

        if (cur.label == goal)
        {
            break;
        }

        // iterate through successors
        for (auto& pair : cur.successors)
        {
            // pair.first = node, pair.second = weight
            temp = pair.first;
            sCost = cur.cost + pair.second;

            if (Index(temp.label, open) != -1)
            {
                if (temp.cost <= sCost) { continue; }
            }
            else if (Index(temp.label, closed))
            {
                if (temp.cost <= sCost) { continue; }
                // TODO: move node from closed to open
            }
            else
            {
                // TODO: add node to open, iterating through to keep sorted
            }
            temp.cost = sCost;
        }
        closed.push_back(cur.label);
    }
    if (cur.label != goal)
    {
        return -1;
    }
}

// returns index of character c in vector v or -1 if c not found
int Index(char c, std::vector<char> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == c)
        {
            return i;
        }
    }

    return -1;
}