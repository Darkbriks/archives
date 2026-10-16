# Compte rendu Tp Mongodb

## Partie 1 : Interroger une collection

### 1. Lister tous les restaurants qui ont un nom en les triant par ordre alphabétique sur le nom.

```
db.restaurants.find({ name: { $ne: '' } }).sort({ name: 1 })
```

**Resultat (2 premiers objets) :**

```
{
  _id: ObjectId('5eb3d669b31de5d588f45c95'),
  address: {
    building: '221',
    coord: [
      -73.9803096,
      40.6600549
    ],
    street: 'Prospect Park West',
    zipcode: '11215'
  },
  borough: 'Brooklyn',
  cuisine: 'Chinese',
  grades: [
    {
      date: 2014-10-29T00:00:00.000Z,
      grade: 'A',
      score: 10
    },
    {
      date: 2014-05-08T00:00:00.000Z,
      grade: 'A',
      score: 4
    },
    {
      date: 2013-02-27T00:00:00.000Z,
      grade: 'A',
      score: 5
    },
    {
      date: 2012-04-09T00:00:00.000Z,
      grade: 'B',
      score: 24
    },
    {
      date: 2011-11-21T00:00:00.000Z,
      grade: 'A',
      score: 11
    }
  ],
  name: '#1 Garden Chinese',
  restaurant_id: '41568346'
}
{
  _id: ObjectId('5eb3d669b31de5d588f484ec'),
  address: {
    building: '3552',
    coord: [
      -73.9093986,
      40.8865351
    ],
    street: 'Johnson Avenue',
    zipcode: '10463'
  },
  borough: 'Bronx',
  cuisine: 'Pizza/Italian',
  grades: [
    {
      date: 2014-10-09T00:00:00.000Z,
      grade: 'A',
      score: 10
    }
  ],
  name: "#1 Me. Nick'S",
  restaurant_id: '50014031'
}
```

### 2. Trouver les restaurant avec de la cuisine italienne (« Italian ») et donner pour chacun d’eux son nom, le type de cuisine et l'adresse.

```
db.restaurants.find({ cuisine: 'Italian' }, { name: 1, cuisine: 1, address: 1 })
```

**Resultat (2 premiers objets) :**

```
{
  _id: ObjectId('5eb3d668b31de5d588f42962'),
  address: {
    building: '10004',
    coord: [
      -74.03400479999999,
      40.6127077
    ],
    street: '4 Avenue',
    zipcode: '11209'
  },
  cuisine: 'Italian',
  name: 'Philadelhia Grille Express'
}
{
  _id: ObjectId('5eb3d668b31de5d588f42965'),
  address: {
    building: '1028',
    coord: [
      -73.966032,
      40.762832
    ],
    street: '3 Avenue',
    zipcode: '10065'
  },
  cuisine: 'Italian',
  name: 'Isle Of Capri Resturant'
}
```

### 3. Lister tous les restaurants dont le nom commence par "A". (On utilisera une expression régulière $regex)

```
db.restaurants.find({ name: { $regex: '^A', $options: 'i' } })
```

** Resultat (2 premiers objets) :**

```
{
  _id: ObjectId('5eb3d668b31de5d588f42943'),
  address: {
    building: '18',
    coord: [
      -73.996984,
      40.72589
    ],
    street: 'West Houston Street',
    zipcode: '10012'
  },
  borough: 'Manhattan',
  cuisine: 'American',
  grades: [
    {
      date: 2014-04-03T00:00:00.000Z,
      grade: 'A',
      score: 9
    },
    {
      date: 2013-04-05T00:00:00.000Z,
      grade: 'A',
      score: 4
    },
    {
      date: 2012-03-21T00:00:00.000Z,
      grade: 'A',
      score: 13
    },
    {
      date: 2011-04-27T00:00:00.000Z,
      grade: 'A',
      score: 5
    }
  ],
  name: 'Angelika Film Center',
  restaurant_id: '40362274'
}
{
  _id: ObjectId('5eb3d668b31de5d588f4298c'),
  address: {
    building: '146',
    coord: [
      -73.9973041,
      40.7188698
    ],
    street: 'Mulberry Street',
    zipcode: '10013'
  },
  borough: 'Manhattan',
  cuisine: 'Italian',
  grades: [
    {
      date: 2014-05-02T00:00:00.000Z,
      grade: 'A',
      score: 11
    },
    {
      date: 2013-03-14T00:00:00.000Z,
      grade: 'A',
      score: 13
    },
    {
      date: 2012-09-26T00:00:00.000Z,
      grade: 'A',
      score: 9
    },
    {
      date: 2012-02-15T00:00:00.000Z,
      grade: 'A',
      score: 13
    },
    {
      date: 2011-09-15T00:00:00.000Z,
      grade: 'A',
      score: 11
    }
  ],
  name: 'Angelo Of Mulberry St.',
  restaurant_id: '40365293'
}
```


### 4. Trouver tous les restaurants italiens ayant au moins un grade supérieur à "B".

```
db.restaurants.find({ cuisine: 'Italian', 'grades.grade': { $lt: 'B' } })
```

**Resultat (2 premiers objets) :**

```
{
  _id: ObjectId('5eb3d668b31de5d588f42974'),
  address: {
    building: '251',
    coord: [
      -73.9775552,
      40.7432016
    ],
    street: 'East   31 Street',
    zipcode: '10016'
  },
  borough: 'Manhattan',
  cuisine: 'Italian',
  grades: [
    {
      date: 2014-04-22T00:00:00.000Z,
      grade: 'A',
      score: 13
    },
    {
      date: 2013-06-19T00:00:00.000Z,
      grade: 'C',
      score: 32
    },
    {
      date: 2012-05-22T00:00:00.000Z,
      grade: 'A',
      score: 12
    }
  ],
  name: 'Marchis Restaurant',
  restaurant_id: '40364668'
}
{
  _id: ObjectId('5eb3d668b31de5d588f429b3'),
  address: {
    building: '146',
    coord: [
      -73.9736776,
      40.7535755
    ],
    street: 'East   46 Street',
    zipcode: '10017'
  },
  borough: 'Manhattan',
  cuisine: 'Italian',
  grades: [
    {
      date: 2014-03-11T00:00:00.000Z,
      grade: 'A',
      score: 11
    },
    {
      date: 2013-07-31T00:00:00.000Z,
      grade: 'C',
      score: 53
    },
    {
      date: 2012-12-19T00:00:00.000Z,
      grade: 'A',
      score: 12
    },
    {
      date: 2012-06-04T00:00:00.000Z,
      grade: 'C',
      score: 45
    },
    {
      date: 2012-01-18T00:00:00.000Z,
      grade: 'C',
      score: 34
    },
    {
      date: 2011-09-28T00:00:00.000Z,
      grade: 'B',
      score: 18
    },
    {
      date: 2011-05-24T00:00:00.000Z,
      grade: 'C',
      score: 52
    }
  ],
  name: 'Nanni Restaurant',
  restaurant_id: '40366157'
}
```

### 5.Lister les noms des restaurants dans le Bronx avec une cuisine autre qu'italienne ou américaine.

```
db.restaurants.find({ borough: 'Bronx', cuisine: { $nin: ['Italian', 'American'] } }, { name: 1 })
```

**Resultat (2 premiers objets) :**

```
{
  _id: ObjectId('5eb3d668b31de5d588f4292e'),
  name: 'Morris Park Bake Shop'
}
{
  _id: ObjectId('5eb3d668b31de5d588f4294a'),
  name: 'Carvel Ice Cream'
}
```

### 6. Rechercher les restaurants ayant un score moyen supérieur à 70 (Attention le score dans grades est composé d'une liste d'objets qu'il faut "déplier").

```
db.restaurants.aggregate([
    { $unwind: "$grades" },
    { $group: {
        _id: "$_id",
        name: { $first: "$name" },
        avgScore: { $avg: "$grades.score" }
        }
    },
    { $match: { avgScore: { $gt: 70 } } }
])
```

**Resultat :**

```
{
  _id: ObjectId('5eb3d669b31de5d588f48751'),
  name: 'Juice It Health Bar',
  avgScore: 75
}
{
  _id: ObjectId('5eb3d669b31de5d588f4897e'),
  name: 'Golden Dragon Cuisine',
  avgScore: 73
}
```

### 7. Lister les restaurants qui n’ont jamais reçu de grade inférieur à 20

```
db.restaurants.aggregate([
    { $unwind: "$grades" },
    { $group: {
        _id: "$_id",
        name: { $first: "$name" },
        score: {$min: "$grades.score"}
        }
    },
    { $match: { score: { $gt: 20 } } }
])
```

```
{
  _id: ObjectId('5eb3d669b31de5d588f4889e'),
  name: 'Mazeish Grill',
  score: 22
}
{
  _id: ObjectId('5eb3d669b31de5d588f476fe'),
  name: 'Ahi Sushi',
  score: 26
}
```

### 8. Trouver les restaurants qui ont reçu au moins un grade qui n'est pas inférieur à 20. (On utilisera $elemMatch)

```
db.restaurants.find({ grades: { $elemMatch: { score: { $gte: 20 } } } })
```

**Resultat (2 premiers objets) :**

```
{
  _id: ObjectId('5eb3d668b31de5d588f4292d'),
  address: {
    building: '469',
    coord: [
      -73.961704,
      40.662942
    ],
    street: 'Flatbush Avenue',
    zipcode: '11225'
  },
  borough: 'Brooklyn',
  cuisine: 'Hamburgers',
  grades: [
    {
      date: 2014-12-30T00:00:00.000Z,
      grade: 'A',
      score: 8
    },
    {
      date: 2014-07-01T00:00:00.000Z,
      grade: 'B',
      score: 23
    },
    {
      date: 2013-04-30T00:00:00.000Z,
      grade: 'A',
      score: 12
    },
    {
      date: 2012-05-08T00:00:00.000Z,
      grade: 'A',
      score: 12
    }
  ],
  name: "Wendy'S",
  restaurant_id: '30112340'
}
{
  _id: ObjectId('5eb3d668b31de5d588f4292f'),
  address: {
    building: '97-22',
    coord: [
      -73.8601152,
      40.7311739
    ],
    street: '63 Road',
    zipcode: '11374'
  },
  borough: 'Queens',
  cuisine: 'Jewish/Kosher',
  grades: [
    {
      date: 2014-11-24T00:00:00.000Z,
      grade: 'Z',
      score: 20
    },
    {
      date: 2013-01-17T00:00:00.000Z,
      grade: 'A',
      score: 13
    },
    {
      date: 2012-08-02T00:00:00.000Z,
      grade: 'A',
      score: 13
    },
    {
      date: 2011-12-15T00:00:00.000Z,
      grade: 'B',
      score: 25
    }
  ],
  name: 'Tov Kosher Kitchen',
  restaurant_id: '40356068'
}
```

## Partie 2 : Mise à jour

### 9. Ajouter une cuisine "Fusion" à tous les restaurants ayant "Other" comme type de cuisine.

```
db.restaurants.updateMany(
    { cuisine : "Other" },
    { $set: { cuisine : "Fusion" } }
)
```

```
{
  acknowledged: true,
  insertedId: null,
  matchedCount: 1011,
  modifiedCount: 1011,
  upsertedCount: 0
}
```

### 10. Supprimer les score null dans les restaurants. Vous commencerez par afficher les restaurants dont au moins un score est null. Ensuite vous réaliserez la suppression qui consiste à identifier les restaurants avec au moins un score null et à supprimer ce score dans les éléments du tableau de grades ($pull).

```
db.restaurants.find({ grades: { $elemMatch: { score: null } } })
```

```
{
  _id: ObjectId('5eb3d668b31de5d588f446e8'),
  address: {
    building: '725',
    coord: [
      -74.01381169999999,
      40.6336821
    ],
    street: '65 Street',
    zipcode: '11220'
  },
  borough: 'Brooklyn',
  cuisine: 'Fusion',
  grades: [
    {
      date: 2015-01-20T00:00:00.000Z,
      grade: 'Not Yet Graded',
      score: null
    }
  ],
  name: 'Swedish Football Club',
  restaurant_id: '41278206'
}
{
  _id: ObjectId('5eb3d669b31de5d588f481d8'),
  address: {
    building: '135',
    coord: [
      -74.0021428,
      40.7347462
    ],
    street: '7 Avenue South',
    zipcode: '10014'
  },
  borough: 'Manhattan',
  cuisine: 'Italian',
  grades: [
    {
      date: 2015-01-20T00:00:00.000Z,
      grade: 'Not Yet Graded',
      score: null
    }
  ],
  name: 'Prime 135',
  restaurant_id: '50011122'
}
```

```
db.restaurants.updateMany(
    { grades: { $elemMatch: { score: null } } },
    { $pull: { grades: { score: null } } }
)
```

```
{
  acknowledged: true,
  insertedId: null,
  matchedCount: 13,
  modifiedCount: 13,
  upsertedCount: 0
}
```

## Partie 3 : Requêtes avec agrégation

### 11. Combien de restaurants dans le Bronx ? On utilisera deux méthodes: la première avec la fonction count, la seconde avec un pipeline d'opérations (fonction aggegate)

```
db.restaurants.countDocuments({ borough: 'Bronx' })
```

```
2338
```

```
db.restaurants.aggregate([
    { $match: { borough: 'Bronx' } },
    { $count: 'totalRestaurants' }
])
```

```
{
  totalRestaurants: 2338
}
```

### 12. Combien de restaurants pour chaque type de cuisine.

```
db.restaurants.aggregate([
    { $group: { _id: "$cuisine", count: { $sum: 1 } } },
])
```

**Resultat (3 premiers objets) :**
```
{
  _id: 'American',
  count: 6183
}
{
  _id: 'Chinese',
  count: 2418
}
{
  _id: 'Café/Coffee/Tea',
  count: 1214
}
```

### 13. Regrouper les restaurants par quartier et afficher le score moyen des grades. Attention il faut déplier la liste des scores afin de générer un document par score (proche d'une jointure externe) avec l'opérateur $unwind.

```
db.restaurants.aggregate([
    { $unwind: "$grades" },
    { $group: {
        _id: "$borough",
        avgScore: { $avg: "$grades.score" }
        }
    }
])
```

**Resultat : (2 premiers objets)**

```
{
  _id: 'Queens',
  avgScore: 11.634865110930088
}
{
  _id: 'Staten Island',
  avgScore: 11.370957711442786
}
{
  _id: 'Brooklyn',
  avgScore: 11.44797595737899
}
{
  _id: 'Bronx',
  avgScore: 11.036186099942562
}
{
  _id: 'Missing',
  avgScore: 9.632911392405063
}
{
  _id: 'Manhattan',
  avgScore: 11.418151216986018
}
```

### Partie 4 : Manipuler plusieurs collections

### 14. Créer une collection reviews avec des commentaires.

```
db.createCollection("reviews")
```

```
{ ok: 1 }
```

### 15. Insérer des données dans reviews pour plusieurs restaurants. Faire en sorte qu'un même restaurant possède plusieurs review

*Données générées avec IA*
```
db.reviews.insertMany([
    {
        "_id": ObjectId("64b8f0f2f1d2c4a5e6b7c8d9"),
        "restaurant_id": "41454445",
        "comment": "Great food and atmosphere!",
        "rating": 5,
        "date": ISODate("2024-01-15T00:00:00Z")
    },
    {
        "_id": ObjectId("64b8f0f2f1d2c4a5e6b7c8da"),
        "restaurant_id": "41454445",
        "comment": "Service was a bit slow.",
        "rating": 3,
        "date": ISODate("2024-02-20T00:00:00Z")
    },
    {
        "_id": ObjectId("64b8f0f2f1d2c4a5e6b7c8db"),
        "restaurant_id": "41454445",
        "comment": "Excellent flavors and great value.",
        "rating": 4,
        "date": ISODate("2024-03-10T00:00:00Z")
    },
    {
        "_id": ObjectId("64b8f0f2f1d2c4a5e6b7c8dc"),
        "restaurant_id": "41299757",
        "comment": "Not worth the hype.",
        "rating": 2,
        "date": ISODate("2024-04-05T00:00:00Z")
    },
    {
        "_id": ObjectId("64b8f0f2f1d2c4a5e6b7c8dd"),
        "restaurant_id": "41299757",
        "comment": "Absolutely excellent experience!",
        "rating": 5,
        "date": ISODate("2024-05-12T00:00:00Z")
    },
    {
        "_id": ObjectId("64b8f0f2f1d2c4a5e6b7c8de"),
        "restaurant_id": "40359480",
        "comment": "Could be better.",
        "rating": 3,
        "date": ISODate("2024-06-18T00:00:00Z")
    },
    {
        "_id": ObjectId("64b8f0f2f1d2c4a5e6b7c8df"),
        "restaurant_id": "40359480",
        "comment": "Excellent service and delicious food.",
        "rating": 5,
        "date": ISODate("2024-07-22T00:00:00Z")
    },
    {
        "_id": ObjectId("64b8f0f2f1d2c4a5e6b7c8e0"),
        "restaurant_id": "40359480",
        "comment": "Will not come back.",
        "rating": 1,
        "date": ISODate("2024-08-30T00:00:00Z")
    },
    {
        "_id": ObjectId("64b8f0f2f1d2c4a5e6b7c8e1"),
        "restaurant_id": "41046505",
        "comment": "An excellent choice for dinner.",
        "rating": 4,
        "date": ISODate("2024-09-15T00:00:00Z")
    },
    {
        "_id": ObjectId("64b8f0f2f1d2c4a5e6b7c8e2"),
        "restaurant_id": "41046505",
        "comment": "Mediocre food, nothing special.",
        "rating": 2,
        "date": ISODate("2024-10-05T00:00:00Z")
    }
])
```

**Resultat :**

```
{
  acknowledged: true,
  insertedIds: {
    '0': ObjectId('64b8f0f2f1d2c4a5e6b7c8d9'),
    '1': ObjectId('64b8f0f2f1d2c4a5e6b7c8da'),
    '2': ObjectId('64b8f0f2f1d2c4a5e6b7c8db'),
    '3': ObjectId('64b8f0f2f1d2c4a5e6b7c8dc'),
    '4': ObjectId('64b8f0f2f1d2c4a5e6b7c8dd'),
    '5': ObjectId('64b8f0f2f1d2c4a5e6b7c8de'),
    '6': ObjectId('64b8f0f2f1d2c4a5e6b7c8df'),
    '7': ObjectId('64b8f0f2f1d2c4a5e6b7c8e0'),
    '8': ObjectId('64b8f0f2f1d2c4a5e6b7c8e1'),
    '9': ObjectId('64b8f0f2f1d2c4a5e6b7c8e2')
  }
}
```

### 16. Trouver les restaurants ayant des commentaires contenants "excellent" ($lookup). On se limitera au commentaire et au nom du restaurant ($project).

```
db.restaurants.aggregate([
    {
        $lookup: {
            from: "reviews",
            localField: "restaurant_id",
            foreignField: "restaurant_id",
            as: "reviews"
        }
    },
    { $unwind: "$reviews" },
    { $match: { "reviews.comment": { $regex: "excellent", $options: "i" } } },
    { $project: { _id: 0, name: 1, comment: "$reviews.comment" } }
])
```

**Resultat :**

```
{
  name: '1 East 66Th Street Kitchen',
  comment: 'Excellent service and delicious food.'
}
{
  name: '1 Darbar',
  comment: 'An excellent choice for dinner.'
}
{
  name: '1 Oak',
  comment: 'Absolutely excellent experience!'
}
{
  name: '1 Or 8',
  comment: 'Excellent flavors and great value.'
}
```


  name: "Juice It Health Bar",