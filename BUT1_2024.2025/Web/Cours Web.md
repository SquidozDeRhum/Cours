

# Cours Web :

**Liste** : 

```html
<ul>
    Liste non ordonnée sans numérotation -bloc-
    Imbrication possible en insérant d'autre <ul></ul>
    Possible d'insérer que des ul ou li
</ul>
```

```html
<li>
	introduit les items au sein des listes ordonnées ou non -bloc-
</li>
```

- **Exemple** : 

```html
<ul>
    <li>Région Corse
        <ul>
            <li>Très beau</li>
        </ul>
    </li>
    <li>Incroyable</li>
</ul>
```

```html
<ol>
    liste ordonnée, avec numérotation
    option "reversed" pour numérotation inverse
</ol>

```

**Liste de définition** : 

```html
<dl>
    	liste de définition
</dl>
```

```html
<dd>

</dd>
```

```html
<dt>

</dt>
```

**Liens** : 

```html
<a href="URLDestination">Pointeur</a> -inline
Contitué d'un pointeur et d'une destination externe ou interne au site
```

- Il faut spécifier le protocole utiliser si la destination est externe au site
- Si la destination est interne au site, on utilise le chemin relatif par rapport à la page actuelle

**Lien intra-document** : 

- Lien dans une page permettant de se déplacer directement dans la page actuelle

```html
<p>
    A-B-C-D <a href ="#lettre-e">E</a>-F
</p>
<article>
	<dl>
        <dt id="lettre-e">Texte</dt>
    </dl>
</article>
```

- On utilise la balise <a> pour aller dans un endroit précis d'un paragraphe. Ex: <a id="flag"></a>
- Cela marche aussi pour une page étrangère <a href="fichier.html#flag"></a>

**Lien de message électronique** : 

```html
<a href="mailto:adresse@nom.fr"></a>
```

**Format bitmap supportés par les navigateurs** : 

- GIF : Jusqu'à 256 couleurs, supporte la transparence ( Graphics Interchange Format)
- PNG : PNG-8, 256 couleurs, PNG-24 256 M de couleurs, supporte la transparence, compression sans perte
- JPEG/JPG : 16 millions de couleurs disponible, ne supporte par la transparence, compression avec ou sans perte
- AVIF : AV1 Image File Format
- WEBP : Web Picture

**Format vectoriel** : 

- SVG : Scalable Vector Graphics
  - Image décrite en XML
  - 16 millions de couleurs disponible
  - Réduction et agrandissement sans perte
  - Support de l'animation et la transparence; taille de fichier réduite

**Insertion d'image** : 

```html
<img src="chemin" alt=" " title=" "> -inline-
```

- Attributs disponible : 

  - alt : définit un texte alternatif quand l'image ne s'affiche pas

  - title : définit un titre, le texte s'affiche lors du survol de la souris

  - width : largeur en pixel

  - height : hauteur en pixel

**Règle d'usage** : 

- Définir les dimensions de l'image
- Choisir un taux de compression
  - Réduire le poids du fichier
  - Optimiser la rapport qualité/poids
  - Exemple : logo 10 ko ; photo 100 ko
- Respecter les proportions pour éviter les déformations
- Regrouper les images dans un répertoire

```html
<figure>
    Permet de contenir une légende pour une image
</figure>
```

```html
<figcaption>
	La légende, s'insert dans un figure
</figcaption>
```

**Exemple** : 

```html
<figure>
	<img src="" alt="" title="">
    <figcaption>Légende de mon image</figcaption>
</figure>
```

Une image peut servir de pointeur en la mettant dans une balise <a>

Différentes zones de cette image peuvent pointer vers différents endroits en définissant des zones

**Zones d'images** : 

```html
<map name="" id="">
	Regroupe les zones réactives d'une image
</map>
```

- name et id sont utilisées pour nommer la carte. Ce nom est utilisé pour faire le lien avec l'image

```html
<area alt="" shape="" coords="">
```

- shape : rect, circle, poly
- coords = définit les coordonées
  - x1, y1, x2, y2 pour un rectangle
  - x, y pour un cercle
  - x1, y2, x2, y2, x3, y3, xn, yn, pour un polygone
- Pour déterminer les coordonnées : https://image.map.net

**Image adaptative** : 

```html
<picture>
	<source srcset="chemin" media="(max-width: 480px)">
    <source srcset="chemin" media ="">
    <img> Image de base
</picture>
```

**Tableau** : 

```html
<table>
    <caption>Titre</caption>
    Tableau
    <tr>
    	Ligne
    </tr>
</table>
```

```html
<th>
	Cellule contenant un intitulé placé en tête de ligne ou de colonne, automatiquement en gras
</th>
```

```html
<td>
	Cellule contenant une donnée
</td>
```

- th ou td peuvent avoir pour attribut
  - colspan = "x" fusion de cellules sur x colonnes
  - rowspan = "x" fusion de cellules sur x lignes

**Options de tableau** :  

```html
<thead>
	
</thead>
<tbody>

</tbody>
<tfoot>

</tfoot>
```

- Il permettent de mieux différencier les éléments d'un tableau

**Encodage des caractères** : 

- La table ASCII ne possède pas d'accents mais est plus légère
- La table UTF-8 permet de d'afficher tous les caractères

**Encodage des caractères spéciaux** : 

- ''<'' et ''>'' sont codés spécialement