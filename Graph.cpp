#include "Graph.h"
#include <sstream>
#include <algorithm>

using namespace std;

void Graph::resetVisited() {
    for (auto& pair : visited) {
        pair.second = false;
    }
}
void Graph::addCity(const string& city) {
    if (adjacencyList.find(city) == adjacencyList.end()) {
        adjacencyList[city] = list<pair<string, int>>();
        visited[city] = false;
    }
}
void Graph::addEdge(const string& city1, const string& city2, int distance) {
    
    adjacencyList[city1].push_back(make_pair(city2, distance));
    adjacencyList[city2].push_back(make_pair(city1, distance));
}
vector<string> Graph::getAllCities() {
    vector<string> cities;
    for (const auto& pair : adjacencyList) {
        cities.push_back(pair.first);
    }
    sort(cities.begin(), cities.end());
    return cities;
}
list<pair<string, int>> Graph::getEdge(const string& city) {
    if (adjacencyList.find(city) != adjacencyList.end()) {
        return adjacencyList[city];
    }
    return list<pair<string, int>>();
} 
void Graph::deleteCity(const string& city) {

    if (adjacencyList.erase(city)) {

        auto i = adjacencyList.begin();

        while (i != adjacencyList.end()) {

            i->second.remove_if([&city](const pair<string, int>& edge) {

                return edge.first == city;

                });

            ++i;

        }
        visited.erase(city);

        cout << "the city '" << city << "' and its connected roads have been deleted.\n";


    }
    else {


        cout << "city '" << city << "' not available.\n";
    }
}
void Graph::deleteEdge(const string& city1, const string& city2) {

    if (adjacencyList.find(city1) == adjacencyList.end() || adjacencyList.find(city2) == adjacencyList.end()) {

        cout << "one of the cities is missing.\n";

        return;
    }

    bool found = false;


    auto i = adjacencyList[city1].begin();

    while (i != adjacencyList[city1].end()) {

        if (i->first == city2) {

            i = adjacencyList[city1].erase(i);

            found = true;

        }

        else {

            ++i;

        }
    }

    i = adjacencyList[city2].begin();

    while (i != adjacencyList[city2].end()) {

        if (i->first == city1) {


            i = adjacencyList[city2].erase(i);

            found = true;
        }
        else {
            ++i;
        }
    }

    if (found) {

        cout << "the road between '" << city1 << "' and '" << city2 << "' has been deleted.\n";


    }
    else {

        cout << "there is no direct route between '" << city1 << "' and '" << city2 << "'.\n";


    }
}
void Graph::displayGraph() 
{
   
    if (adjacencyList.empty()) {

        cout << "the graph is empty.\n";

        return ;
    }


    cout << "data of graph:\n";
   

    auto i = adjacencyList.begin();

    while (i != adjacencyList.end()) {

        cout << i->first << " connected with: ";


        if (i->second.empty()) {

            cout << "there are no roads";

        }

        else {
            auto edgeIt = i->second.begin();

            while (edgeIt != i->second.end()) {

                cout << edgeIt->first << " (" << edgeIt->second << " km), ";

                ++edgeIt;
            }
        }

        cout << "\n";

        ++i;
    }
    return ;
}
void Graph::BFS(const string& startCity) {

    if (adjacencyList.find(startCity) == adjacencyList.end()) {

        cout << "the city does not exist.\n";

        return;

    }
    resetVisited();

    queue<string> q;

    q.push(startCity);

    visited[startCity] = true;


    cout << "search result of (BFS): ";


    while (!q.empty()) {

        string current = q.front();

        q.pop();

        cout << current << " ";


        auto i = adjacencyList[current].begin();


        while (i != adjacencyList[current].end()) {

            if (!visited[i->first]) {

                visited[i->first] = true;

                q.push(i->first);

            }

            ++i;

        }
    }

    cout << "\n";

}
void Graph::DFS(const string& startCity) {

    if (adjacencyList.find(startCity) == adjacencyList.end()) {

        cout << "the city does not exist.\n";

        return;
    }

    resetVisited();

    stack<string> s;

    s.push(startCity);


    cout << "search result of (DFS): ";


    while (!s.empty()) {

        string current = s.top();

        s.pop();

        if (!visited[current]) {

            visited[current] = true;

            cout << current << " ";


            auto i = adjacencyList[current].begin();

            while (i != adjacencyList[current].end()) {

                if (!visited[i->first]) {

                    s.push(i->first);

                }
                ++i;
            }
        }
    }

    cout << "\n";
}
void Graph::dijkstra(const string& startCity, const string& endCity) {

    if (adjacencyList.find(startCity) == adjacencyList.end() || adjacencyList.find(endCity) == adjacencyList.end()) {

        cout << "one of the cities is not present.\n";

        return;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    unordered_map<string, int> distances;

    unordered_map<string, string> previous;


    auto i = adjacencyList.begin();

    while (i != adjacencyList.end()) {

        distances[i->first] = numeric_limits<int>::max();

        ++i;
    }

    distances[startCity] = 0;

    pq.push(make_pair(0, startCity));


    while (!pq.empty()) {

        string current = pq.top().second;

        pq.pop();


        if (current == endCity)

            break;

        auto neighborIt = adjacencyList[current].begin();

        while (neighborIt != adjacencyList[current].end()) {

            int newDist = distances[current] + neighborIt->second;

            if (newDist < distances[neighborIt->first]) {

                distances[neighborIt->first] = newDist;

                previous[neighborIt->first] = current;

                pq.push(make_pair(newDist, neighborIt->first));

            }

            ++neighborIt;

        }
    }


    if (distances[endCity] == numeric_limits<int>::max()) {

        cout << "there is no path between '" << startCity << "' and '" << endCity << "'.\n";

        return;
    }

    vector<string> path;


    for (string at = endCity; at != ""; at = previous[at]) {

        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    cout << "the shortest distance between '" << startCity << "' and '" << endCity << "': " << distances[endCity] << " km\n";

    cout << "the path: ";

    for (size_t i = 0; i < path.size(); i++) {

        if (i != 0) cout << " -> ";

        cout << path[i];

    }

    cout << "\n";
}
void Graph::saveToFile(const string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file for writing");
    }

    
    for (const auto& city : getAllCities()) {
        file << "CITY " << city << "\n";
    }

   
    for (const auto& pair : adjacencyList) {
        for (const auto& connection : pair.second) {
           
            if (pair.first < connection.first) {
                file << "CONNECTION " << pair.first << " "
                    << connection.first << " " << connection.second << "\n";
            }
        }
    }

    file.close();
}
void Graph::loadFromFile(const string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file for reading");
    }

   
    adjacencyList.clear();
    visited.clear();

    std::string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string type;
        iss >> type;

        if (type == "CITY") {
            string city;
            iss >> city;
            addCity(city);
        }
        else if (type == "CONNECTION") {
            string city1, city2;
            int distance;
            iss >> city1 >> city2 >> distance;
            addEdge(city1, city2, distance);
        }
    }

    file.close();
}