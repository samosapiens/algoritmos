/*
REFERENCIAS:
https://gist.github.com/saichandrasekhar/d5c75963849661aedeb2
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
using Long = long long;

const Long infty = 10000;   // Umbral de distancia infinita
const int N = 100001;       // Máxima capacidad de datos enteros requeridos para cualquier caso

// Tipo de dato Point
struct point {
  Long x, y;
}p[N];

//-------------------------------------------------------------------------------------------------------
// Métodos y Subrutinas Principales
//-------------------------------------------------------------------------------------------------------

// Criterio de ordenamiento en la dimensión X
bool byX(const int &i, const int &j) {
  return p[i].x < p[j].x;
}

// Criterio de ordenamiento en la dimensión Y
bool byY(const int &i, const int &j) {
  return p[i].y < p[j].y;
}

// f(x) = x**2
Long sqr(Long a) {
  return a * a;
}

// Cálculo de la distancia Euclidea entre dos puntos
Long dist(int a, int b) {
  return sqr(p[a].x - p[b].x) + sqr(p[a].y - p[b].y);
}

int tmp[N], X, Y;
Long minDist;

// Método de fuerza bruta para hallar la menor distancia
Long brute(int ord[], int n) {
  // Ordenar los n p en la dimensión Y
  sort(ord, ord + n, byY);
  // Suponer los puntos muy lejanos
  Long ret = infty;
  // Hallar la distancia entre todos los posibles puntos
  for (int i = 0; i < n; i++) {
    // No se consideran los casos repetidos (i.e: dist(p1, p2) == dist(p2, p1)
    for (int j = i + 1; j < n; j++) {
      // Verificar si es la menor distancia encontrada hasta ahora
      ret = min(ret, dist(ord[i], ord[j]));
      // En ese caso actualizar el valor de la menor distancia y almacenar los p X y Y más cercanos
      if (minDist>ret) {
        minDist = ret;
        X = ord[i], Y = ord[j];
      }
    }
  }
  return ret;
}

// Hallar los p más cercanos en el arreglo ord de tamaño n recursivamente
Long solve(int ord[], int n) {
  // no se hallaron p cercanos
  if (n == 1) return infty;
  // Para arreglos de tamaños pequeños ordenar usando fuerza bruta
  if (n <= 10) return brute(ord, n);
  // En caso contrario
  int left = (n + 1) / 2;
  Long midx = p[ord[left]].x;
  // Dividir el problema en dos subproblemas de tamaño n/2
  Long delta = min(solve(ord, left), solve(ord + left, n - left));
  // Mezclar los dos resultados ordenando en la dimensión Y
  int i = 0, j = left, k = 0;
  while (i < left || j < n) {
    if (i != left && (j == n || p[ord[i]].y < p[ord[j]].y)) tmp[k++] = ord[i++];
    else tmp[k++] = ord[j++];
  }
  memcpy(ord, tmp, sizeof(int)*n);
  // Considerar p a una distancia delta del centro en dirección X
  k = 0;
  for (int i = 0; i < n; i++) {
    int u = ord[i];
    if (sqr(p[u].x - midx) < delta) tmp[k++] = u;
  }
  // Hallar los p más cercanos en dirección X y Y
  Long ret = delta;
  for (int i = 0; i < k; i++) {
    int u = tmp[i];
    for (int j = i + 1; j < k; j++) {
      int v = tmp[j];
      if (sqr(p[u].y - p[v].y) >= ret) break;
      ret = min(ret, dist(u, v));
      if (minDist>ret) {
        minDist = ret;
        X = u, Y = v;
      }
    }
  }
  return ret;
}

//-------------------------------------------------------------------------------------------------------
// Programa Principal
//-------------------------------------------------------------------------------------------------------

int a[N], ord[N], n;

int main() {
    // Leer entrada de entero (n -> cantidad de puntos)
    scanf("%d", &n);
    //printf("N: %d\n", n);

    // Procesar mientras el valor recibido de n sea mayor de 0
    while(n>0) {
        // Leer n puntos y registrar el orden en que fueron recibidos
        for (int i = 0; i < n; ++i) {
            ord[i] = i;
            scanf("%lld%lld", &p[i].x, &p[i].y);
            //printf("\tP%d: (%lld, %lld)\n", ord[i], p[i].x, p[i].y);
        }

        // Ordenar los n puntos en la dimensión X
        sort(ord, ord + n, byX);

        // Hallar los puntos más cercanos
        minDist = infty;
        minDist = solve(ord, n);
        if (X>Y) swap(X, Y); // mostrar indice de los p ordenadamente

        //printf("mindist: %lld, infty: %lld\n", minDist, infty);
        if(minDist == infty) printf("INFINITY\n");
        else printf("%.4lf\n", (double)(sqrt(minDist+0.)));
        
        // Leer n para verificar si se debe volver a ejecutar el algoritmo
        scanf("%d", &n);
        //printf("N: %d\n", n);
    }
    
    return 0;
}