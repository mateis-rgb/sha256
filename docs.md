# Documentation de la Bibliothèque SHA-256

## Introduction
Cette bibliothèque implémente l'algorithme SHA-256 pour le hachage de données. Elle fournit des fonctions permettant d'initialiser, mettre à jour et finaliser un hachage, ainsi que des fonctions pratiques pour obtenir un hachage sous forme hexadécimale ou binaire.

## Structures et Types

### `sha256`
```c
typedef struct {
    uint32_t state[8];
    uint64_t n_bits;
    uint8_t buffer[64];
    size_t buffer_counter;
} sha256;
```
Cette structure stocke l'état interne du calcul SHA-256, incluant les registres d'état, le nombre de bits traités, un tampon de 64 octets et un compteur de tampon.

---
## Fonctions

### `void sha256_init(sha256 *sha)`
Initialise une instance de `sha256` avec les valeurs initiales de l'algorithme SHA-256.

**Paramètres :**
- `sha` : Pointeur vers la structure `sha256` à initialiser.

---

### `void sha256_append(sha256 *sha, const void *src, size_t n_bytes)`
Ajoute des données au hachage en cours.

**Paramètres :**
- `sha` : Pointeur vers la structure SHA-256.
- `src` : Pointeur vers les données à ajouter.
- `n_bytes` : Nombre d'octets à ajouter.

---

### `void sha256_finalize(sha256 *sha)`
Finalise le calcul du hachage en ajoutant le padding et la longueur totale du message.

**Paramètres :**
- `sha` : Pointeur vers la structure SHA-256.

---

### `void sha256_finalize_hex(sha256 *sha, char *dst_hex65)`
Finalise le calcul et stocke le résultat sous forme de chaîne hexadécimale.

**Paramètres :**
- `sha` : Pointeur vers la structure SHA-256.
- `dst_hex65` : Pointeur vers un tampon de 65 octets pour stocker la chaîne hexadécimale.

---

### `void sha256_finalize_bytes(sha256 *sha, void *dst_bytes32)`
Finalise le calcul et stocke le résultat sous forme binaire (32 octets).

**Paramètres :**
- `sha` : Pointeur vers la structure SHA-256.
- `dst_bytes32` : Pointeur vers un tampon de 32 octets pour stocker le hachage.

---

### `void sha256_hex(const void *src, size_t n_bytes, char *dst_hex65)`
Hache directement un bloc de données et retourne le résultat en hexadécimal.

**Paramètres :**
- `src` : Pointeur vers les données.
- `n_bytes` : Nombre d'octets des données.
- `dst_hex65` : Pointeur vers un tampon de 65 octets pour stocker le hachage.

---

### `void sha256_bytes(const void *src, size_t n_bytes, void *dst_bytes32)`
Hache directement un bloc de données et retourne le résultat sous forme binaire.

**Paramètres :**
- `src` : Pointeur vers les données.
- `n_bytes` : Nombre d'octets des données.
- `dst_bytes32` : Pointeur vers un tampon de 32 octets pour stocker le hachage.

---

### `char * hash(char * src)`
Hache une chaîne de caractères et retourne une chaîne hexadécimale statique.

**Paramètres :**
- `src` : Pointeur vers la chaîne à hacher.

**Retourne :**
- Une chaîne de caractères hexadécimale de 64 caractères.

---

### `unsigned char verify(char * text, char * hash)`
Compare deux chaînes de hachage pour vérifier si elles correspondent.

**Paramètres :**
- `text` : Pointeur vers la première chaîne.
- `hash` : Pointeur vers la seconde chaîne.

**Retourne :**
- `1` si les chaînes sont identiques.
- `0` sinon.

---
## Exemples d'Utilisation

### Hachage d'une chaîne et affichage du résultat
```c
#include <stdio.h>
#include "sha256.h"

int main() {
    char hash_output[65];
    const char *message = "Hello, World!";
    
    sha256_hex(message, strlen(message), hash_output);
    printf("SHA-256: %s\n", hash_output);
    return 0;
}
```

### Vérification d'un hachage
```c
#include <stdio.h>
#include "sha256.h"

int main() {
    char *message = "password123";
    char *hashed = hash(message);
    
    if (verify(hashed, hash(message))) {
        printf("Le hachage correspond.\n");
    } else {
        printf("Le hachage ne correspond pas.\n");
    }
    
    return 0;
}
```

## Conclusion
Cette implémentation de SHA-256 fournit des fonctions pratiques pour générer des hachages de données. Elle peut être utilisée pour garantir l'intégrité des données et la sécurité des mots de passe. Pour une utilisation dans des applications critiques, assurez-vous que votre environnement de compilation prend en charge les types de données et fonctions utilisés ici.

