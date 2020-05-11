# Projet de MMORPG

*Est-ce que je l'écris en anglais un jour ?*  
*Il faudra bientôt faire un fichier de game design par différente partie.*  

Un rpg dans lequel trois factions s’affrontent : celle de la civilisation, celle de la nature et celle de l’ombre.  
Deux seulement sont jouables : celle de **la civilisation, détentrice du secret de la technologie**, et celle de **la nature, protectrice du secret de la magie**.  
Chacune de ces factions tente de s’emparer des pouvoirs de leurs ennemis en menant des attaques contre ceux-ci, que ce soit par la force ou par la ruse.  

---

## Monde

### La civilisation

La civilisation est dirigée par un roi.  
Son pouvoir est centralisé autour d'une grande cité dorée, ayant à peu près la forme de la tour de Babel.  
Le roi gère ses contrées grâce à des seigneurs sous son autorité, protégeant leurs terres et gérant leurs armées.  
Elle étend son pouvoir en construisant de nouvelles villes sous le signe de l'industrie.  

### La nature

La nature est gouvernée par un conseil de sages, chacun étant représentant de sa tribu.  
Celles-ci peuvent se trouver dans les forêts, plaines, montagnes, et se fondent avec le paysage.  
Certaines sont nomades, les hommes de la nature peuvent vivre de la chasse ou de la pêche.  
Leur force leur provient de la source de magie, avec laquelle ils peuvent se connecter grâce à leur communion avec la nature.  

### L'ombre

L’ombre est composée de créatures malfaisantes, vivant cachée dans les profondeurs terrestres, et tentant de corrompre les humains.  

### Géographie

### Conquêtes

Chaque fonction possède une province imprenable, celle de la source de son pouvoir et de son commandement.  
Les autres peuvent changer de propriétaire à la suite de batailles ou de trahisons.  

Au début du jeu, certaines factions n'appartiennent à personne et sont vierges de tout conflit ou de trace humaine ?  

---

## Scénario

### Histoire du monde

### Quêtes

Les quêtes proposées aux joueurs dépendent de la situation actuelle du monde, du statut du personnage et du rôle du PNJ.  

### Impact des joueurs

Les joueurs peuvent impacter le déroulement des évènements grâce aux quêtes auxquelles ils participent, pouvant changer la situation d'un PNJ ou d'une ville / province, par exemple par le biais des conquêtes territoriales.  

---

## Personnages joueurs

### Gameplay

#### Déplacement

Le joueur peut se déplacer avec 4 touches qu'il peut choisir ou avec la souris, en cliquant à l'endroit de sa destination (A* ?).  

#### Attaques de base

#### Sorts

### Graphismes

#### Animations

8 directions différentes pour le joueur  
Animations de déplacement (pas, course)  
Animations d'attaques de base et de sorts  

### Personnalisation

#### Faction

##### Honneur

L'honneur résume les bonnes et mauvaises actions qu'un joueur a réalisées pour sa faction.  
Que se passe-t'il quand l'honneur tombe à 0 ?  

##### Statut

Le statut d'un personnage représente son rôle dans sa faction et les quêtes qui peuvent lui être proposées.  
Attribue-t'on un niveau à chaque statut, de manière à ce qu'un joueur puisse se spécialiser dans tel ou tel ?  

* Guerrier
* Assassin
* Espion
* Mercenaire
* Éclaireur ?

#### Statistiques

| Nom            | Détails                                  |
| :------------- | :--------------------------------------: |
| Vie            | Le joueur meurt quand ses PV tombent à 0 |

Que se passe-t'il quand un joueur meurt ? Où reparaît-t'il ? Subit-il une sanction ?  

#### Compétences

#### Équipement

* Couvre-chef
* Armure / plastron
* Cape ?
* Bas / pantalon
* Bottes / chaussures

---

## Système de combat

Tour par tour ou open world ?

---

## Monstres

---

## PNJ

### Rôles

### Intelligence artificielle

### Statistiques

| Nom             | Détails                       |
| :-------------- | :---------------------------: |
| Argent          |                               |
| Objets          |                               |

### Liens entre PNJ

### Dialogues

---

## Menus, états de jeu

### Menu principal

### Création de personnage

| Choix de création | Détails                                                    |
| :---------------- | :--------------------------------------------------------: |
| Faction           |                                                            |
| Sexe              |                                                            |
| Apparence         | Taille ? Couleurs des habits, de la peau, des cheveux      |


### Open world

Le jeu est en 2D vue de 3/4 (ou isométrique ?), de manière à simuler de la 3D.  
Il y a un scrolling continu conservant le joueur au milieu de son écran.  

Le joueur voit sa liste de sorts et ses caractéristiques importantes (PV).  
Il y a également un menu permettant d'accéder à la souris aux différents états de jeu accessibles au clavier.  

### Carte

### Inventaire

### Options

Trois boutons disponibles:  
`Langue`, `Contrôles`, et `Options graphiques`  

Quand on clique sur `Langue`, un menu déroulant apparaît pour choisir notre langue, et le changement se fait sans redémarrer le jeu.  
Quand on clique sur `Contrôles` ou sur `Options graphiques`, on change d'état de jeu. (cf ci-dessous)  

#### Langues

Anglais et français  

#### Contrôles

Bouton de retour pour revenir aux options  

Quand on clique sur un des contrôles avec la souris, le jeu attend que l'on appuie sur une touche pour lui associer le contrôle associé.  
Que se passe-t'il alors quand on clique sur une touche déjà liée ?  
On a tout de même la possibilité de cliquer sur retour pour revenir aux options, et on annule alors l'attente d'association.  

| Choix des associations à modifier  |
| :--------------------------------- |
| Chacune des touches de déplacement |
| Chacun des sorts                   |
| Carte                              |
| Inventaire                         |

| Liste des touches réservées |
| :-------------------------- |
| Échap                       |

##### Associations initiales

Choisis-t'on les associations intiales en fonction de la langue du joueur / de la disposition de son clavier ?

| Touche                   | Action                                     |
| :----------------------- | :----------------------------------------: |
| Échap                    | Revenir à l'état précédent                 |
| Clic (gauche ou droit ?) | Déplacer son personnage à l'endroit cliqué |
| ?                        | Déplacer son personnage à gauche           |
| ?                        | Déplacer son personnage à droite           |
| ?                        | Déplacer son personnage en haut            |
| ?                        | Déplacer son personnage en bas             |
| M                        | Ouvrir et fermer la carte                  |
| I                        | Ouvrir et fermer son inventaire            |
| ?                        | Ouvrir et fermer les options ?             |

#### Options graphiques

Bouton de retour pour revenir aux options  

| Options disponibles |
| :------------------ |
| Résolution ?        |
| Plein écran         |

---

## Son

### Musiques

### Sons ambiants

---

## Graphismes