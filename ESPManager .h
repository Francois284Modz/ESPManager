
struct enemy_t {
    void *object;
};

class ESPManager {
public:
    std::vector<enemy_t*> enemies;

    ESPManager() {
        enemies = std::vector<enemy_t*>();
    }

    bool isEnemyPresent(void* enemyObject) {
        for (auto enemy : enemies) {
            if (enemy->object == enemyObject) {
                return true;
            }
        }
        return false;
    }

    void removeEnemy(enemy_t* enemy) {
        for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i] == enemy) {
                enemies.erase(enemies.begin() + i);
                return;
            }
        }
    }

    void tryAddEnemy(void* enemyObject) {
        if (isEnemyPresent(enemyObject)) {
            return;
        }

        //if (PlayerDead(enemyObject)) {
            //return;
        //}

        enemy_t* newEnemy = new enemy_t();

        newEnemy->object = enemyObject;

        enemies.push_back(newEnemy);
    }

    void updateEnemies() {
        for (int i = 0; i < enemies.size(); i++) {
            enemy_t* current = enemies[i];

            //if (PlayerDead(current->object)) {
               // enemies.erase(enemies.begin() + i);
           // }
        }
    }

    void removeEnemyGivenObject(void* enemyObject) {
        for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i]->object == enemyObject) {
                enemies.erase(enemies.begin() + i);
                return;
            }
        }
    }
};
