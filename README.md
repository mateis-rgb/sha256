# 🔒 Implémentation de SHA-256 en C

Cette bibliothèque fournit une implémentation simple et efficace de l'algorithme SHA-256 en C. Elle permet de générer des empreintes SHA-256 sous forme hexadécimale ou binaire.

---

## 🚀 Fonctionnalité Principale : `hash()`
La fonction `hash()` permet de hacher une chaîne de caractères en une seule ligne de code :

### ✅ Exemple d'utilisation :
```c
#include <stdio.h>
#include "sha256.h"

int main() {
    char *message = "Hello, World!";
    char *hashed = hash(message);
    
    printf("SHA-256: %s\n", hashed);
    return 0;
}
```

🎯 **Pourquoi utiliser `hash()` ?**
- ✅ Facile à utiliser : une seule ligne pour obtenir un SHA-256
- ✅ Retourne directement une chaîne hexadécimale
- ✅ Pas besoin d'initialiser une structure SHA-256

---

## 🔧 Méthode Avancée : Hachage Manuel (Sans `hash()`)
Si vous souhaitez plus de contrôle, vous pouvez utiliser directement l'API SHA-256 :

### 📌 Exemple de hachage manuel :
```c
#include <stdio.h>
#include <string.h>
#include "sha256.h"

int main() {
    sha256 sha;
    char hash_output[65];  // 64 caractères hexadécimaux + '\0'
    const char *message = "Hello, World!";

    sha256_init(&sha);
    sha256_append(&sha, message, strlen(message));
    sha256_finalize_hex(&sha, hash_output);

    printf("SHA-256 (manuel) : %s\n", hash_output);
    return 0;
}
```
🔹 **Avantages de cette méthode :**  
- Permet de traiter les données en plusieurs morceaux (streams de données)  
- Plus flexible pour des cas d'utilisation avancés  

---

## 🔍 Vérification d'un Hachage avec `verify()`
Vous pouvez comparer un message haché avec une autre empreinte SHA-256 :

### ✅ Exemple de vérification :
```c
#include <stdio.h>
#include "sha256.h"

int main() {
    char *message = "password123";
    char *hashed = hash(message);
    
    if (verify(hashed, hash(message))) {
        printf("✅ Le hachage correspond.\n");
    } else {
        printf("❌ Le hachage ne correspond pas.\n");
    }
    
    return 0;
}
```

🎯 **Pourquoi utiliser `verify()` ?**
- Comparaison rapide et simple de hachages
- Pratique pour les mots de passe ou l'intégrité des données

---

## 🛠️ Installation et Compilation

### 🔹 Prérequis
- Un compilateur C (GCC, Clang, MSVC, etc.)
- Un environnement compatible avec la bibliothèque standard du C

### 🔹 Compilation avec GCC :
```sh
gcc -o sha256_example sha256.c main.c
```

---

## 📚 Documentation
Une documentation détaillée est disponible dans le fichier [Sha256 Documentation](https://github.com/mateis-rgb/sha256/blob/main/docs.md).


## 📜 Licence
Ce projet est sous licence MIT. Vous êtes libre de l'utiliser, le modifier et le distribuer.

## 👍 Remerciments
L'implémentation de ce projet est à l'origine de [983](https://github.com/983/SHA-256) et réarrangé par [cinqlair](https://github.com/cinqlair).

## 🤝 Contribuer
Les contributions sont les bienvenues ! N'hésitez pas à ouvrir une issue ou une pull request.

---

⭐ **Si ce projet vous est utile, pensez à laisser une étoile sur GitHub !**
