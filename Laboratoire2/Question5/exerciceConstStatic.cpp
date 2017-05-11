/**
 * \file exerciceConstStatic.cpp
 * \brief Un main() pour tester les fonctions
 * \author Jean-Francis Roy
 * \author Ludovic Trottier
 * \author Claude Bolduc
 * \version 0.4
 * \date Mai 2016
 *
 */
#include <cmath>     // Pour la librairie math.h du C
#include <iostream>  // Les entrées/sorties

using namespace std;

struct Point {
	//static float x, y;
	float x, y;

	Point() {
		x = 0.0f;
		y = 0.0f;
	}

	float distanceDeLOrigine(Point p_point) const {
		return sqrt(p_point.x * p_point.x + p_point.y * p_point.y);
	}

	float distanceDeLOrigine() const {
		static int nbFois = 0;
		cout << "Cette fonction a été appelée " << ++nbFois << " fois." << endl;
		return sqrt(x * x + y * y);
	}

	void rotation(float p_angle) {
		float x2 = x * cos(p_angle) + y * sin(p_angle);
		float y2 = -x * sin(p_angle) + y * cos(p_angle);
		x = x2;
		y = y2;
	}

	Point tourne(float p_angle) {
		rotation(p_angle);

		// Le mot-clé this est un pointeur sur l'objet considéré. Ainsi, lorsque l'on appelle une méthode
		// d'une classe (ou struct), celle-ci reçoit en plus de ses paramètres, un paramètre caché :
		// le pointeur this.
		return *this; // On retourne donc ici une copie de l'objet courant
	}
};

//float Point::x = 0.0f;
//float Point::y = 0.0f;

int indiceDuPlusProche(const Point * p_source, int p_nbPoints) {
	if (p_nbPoints <= 0) {
		return -1;
	}

	int indexMin = 0;
	float distMin = p_source[0].distanceDeLOrigine();

	for (int i = 1; i < p_nbPoints; ++i) {
		float const d = p_source[i].distanceDeLOrigine();
		if (d < distMin) {
			distMin = d;
			indexMin = i;
		}
	}

	return indexMin;
}

int main() {
	Point mes_points[3];
	mes_points[0].x = 2.4f;
	mes_points[0].y = 3.6f;
	mes_points[1].x = 1.1f;
	mes_points[1].y = 8.7f;
	mes_points[2].x = 7.5f;
	mes_points[2].y = 8.2f;

	int indexPlusProche = indiceDuPlusProche(mes_points, 3);
	cout << "Index du point le plus proche: " << indexPlusProche << std::endl;
	return 0;
}
