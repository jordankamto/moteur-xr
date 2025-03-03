# 🚀 Moteur XR Modulaire – ANI-PJ 4068  

## 📌 Description  
Ce projet s'inscrit dans le cadre du cours **ANI-PJ 4068 : Coder pour la VR, l'XR et l'AR II**. L'objectif est de concevoir et développer un moteur de réalité augmentée (AR) modulaire en intégrant **SDL3, OpenGL et ImGui**. Ce moteur permettra d'expérimenter des fonctionnalités avancées comme le **tracking d'objets, la détection de plans et le rendu 3D interactif**, tout en suivant une **architecture modulaire et orientée objet** pour une meilleure extensibilité.  

---

## 🛠️ Technologies utilisées  
- **SDL3** – Gestion de la fenêtre, des événements et du rendu  
- **OpenGL** – Rendu 3D en temps réel  
- **ImGui** – Interface graphique interactive  
- **C++** – Langage principal avec une approche orientée objet  
- **CMake** – Gestion de la compilation multi-plateforme  

---

## 📂 Structure du projet  
```
📁 MOTEUR-XR 
📁 build                 # Dossier de génération des fichiers de compilation  
│  
├─ 📁 external           # Dépendances externes  
│   ├─ 📁 bin\Premake5   # Outils de génération Premake  
│   └─ 📁 libs           # Bibliothèques tierces  
│       ├─ backends      # Backend ImGui  
│       ├─ Glad2         # Gestion des extensions OpenGL  
│       ├─ imgui         # Bibliothèque ImGui  
│       ├─ misc          # Fichiers divers  
│       └─ SDL3          # Bibliothèque SDL3  
│  
├─ 📁 moteur-xr          # Répertoire principal du moteur  
│   ├─ 📁 src            # Code source  
│   │   ├─ imgui         # Interfaces utilisateur avec ImGui  
│   │   └─ moteur-xr.cpp  # Point d'entrée du moteur  
│   ├─ moteur-xr.vcxproj # Projet Visual Studio  
│   ├─ moteur-xr.vcxproj.filters # Filtres Visual Studio  
│   └─ premake5.lua      # Script de configuration Premake  
│  
├─ 📁 tools              # Outils de build et de génération  
├─ build.bat             # Script de compilation  
├─ gen.bat               # Génération des fichiers de projet  
├─ run.bat               # Exécution du moteur  
├─ premake5.lua          # Script de génération Premake  
└─ .gitignore            # Fichiers à ignorer par Git  
│  
├─ imgui.ini             # Fichier de configuration ImGui  
├─ moteur-xr.sln         # Solution Visual Studio  
└─ README.md             # Documentation du projet  

```

---

## 🔧 Installation et Compilation  

### 1️⃣ Prérequis  
Assurez-vous d'avoir installé :  
- **CMake** (version 3.20+)  
- **Un compilateur C++ (GCC, Clang, MSVC)**  
- **SDL3, OpenGL, ImGui**  

### 2️⃣ Cloner le dépôt  
```bash
git clone https://github.com/utilisateur/moteur-ar-modulaire.git
cd moteur-ar-modulaire
```

### 3️⃣ Générer et compiler avec CMake  
```bash
mkdir build && cd build
cmake ..
make
```

### 4️⃣ Exécuter le moteur  
```bash
./moteur-ar
```

---

## ✨ Fonctionnalités principales  
✅ **Affichage et rendu 3D en OpenGL**  
✅ **Gestion des événements avec SDL3**  
✅ **Interface utilisateur intégrée avec ImGui**  
✅ **Détection de plans et tracking d'objets AR**  
✅ **Architecture modulaire et extensible**  

---

## 📌 Objectifs pédagogiques  
📍 Comprendre et implémenter un **moteur AR** de A à Z  
📍 Expérimenter **les bases du rendu 3D et de la programmation bas niveau**  
📍 Concevoir un **système modulaire et extensible**  
📍 Intégrer **des outils avancés pour la gestion des interfaces et du tracking AR**  

---

## 🛠️ Roadmap du projet  
- [x] Configuration du projet avec SDL3 et OpenGL  
- [ ] Implémentation du rendu 3D  
- [ ] Ajout du système de tracking  
- [ ] Intégration de l’interface utilisateur  
- [ ] Optimisation et modularisation du moteur  

---

## 🤝 Contribuer  
Les contributions sont les bienvenues !  
1. **Fork** le projet  
2. Crée une **branche** (`git checkout -b feature-ma-fonctionnalite`)  
3. **Commit** tes modifications (`git commit -m "Ajout d'une nouvelle fonctionnalité"`)  
4. **Push** vers ta branche (`git push origin feature-ma-fonctionnalite`)  
5. Ouvre une **Pull Request**  

---

## 📜 Licence  
Ce projet est sous licence **MIT** – voir le fichier [LICENSE](LICENSE) pour plus de détails.  
