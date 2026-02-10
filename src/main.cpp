#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <climits>

using namespace std;

/*
 Cada Node representa um nó da rede DHT.
 Ele possui um ID e uma tabela local de dados e guarda algumas chaves localmente.
*/
class Node {
public:
    int id;
    map<string, string> table;

    Node(int nodeId) {
        id = nodeId;
    }
};

/*
 Classe que representa a DHT.
 A DHT controla todos os nós e decide em qual nó cada chave será armazenada.
*/
class DHT {
private:
    vector<Node> nodes;

    // Distância usada no Kademlia: XOR
    // O Kademlia usa XOR pra medir distância entre nós e chaves. O nó com menor XOR é o responsável.
    int xorDistance(int a, int b) {
        return a ^ b;
    }

    // Hash simples da chave
    int hashKey(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash;
    }

    // Encontra o nó mais próximo da chave
    Node* closestNode(int keyHash) {
        Node* best = nullptr;
        int minDist = INT_MAX;

        for (auto& node : nodes) {
            int dist = xorDistance(node.id, keyHash);
            if (dist < minDist) {
                minDist = dist;
                best = &node;
            }
        }
        return best;
    }

public:
    // Adiciona um nó à DHT
    void addNode(int id) {
        nodes.emplace_back(id);
        cout << "Nó " << id << " adicionado\n";
    }

    // Armazena uma chave
    // A chave é transformada em número, a DHT escolhe o nó mais próximo e salva.
    void store(const string& key, const string& value) {
        int keyHash = hashKey(key);
        Node* node = closestNode(keyHash);
        node->table[key] = value;
        cout << "Chave '" << key << "' armazenada no nó " << node->id << "\n";
    }

    // Busca uma chave
    // A DHT calcula o mesmo nó responsável e procura o valor.
    void find(const string& key) {
        int keyHash = hashKey(key);
        Node* node = closestNode(keyHash);

        if (node->table.count(key)) {
            cout << "Valor encontrado: " << node->table[key] << "\n";
        } else {
            cout << "Chave não encontrada\n";
        }
    }
};

int main() {
    DHT dht;

    dht.addNode(10);
    dht.addNode(40);
    dht.addNode(90);

    dht.store("arquivo1", "dados do arquivo 1");
    dht.store("arquivo2", "dados do arquivo 2");

    dht.find("arquivo1");
    dht.find("arquivo2");
    dht.find("arquivo_inexistente");

    return 0;
}