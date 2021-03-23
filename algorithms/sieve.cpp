/* Guarda en primes los números primos menores o iguales a MAX. Para saber si
 * pf[i] es un número primo, hacer: if (pf[i]==i).*/

const int MAX = 1e7;
int pf[MAX + 1];  // guarda el factor primo del numero i
vector<int> pr;   // guarda los numeros primos

void init() {
  memset(pf, 0, sizeof(pf));
  for (int i = 2; i <= MAX; ++i) {
    if (pf[i] == 0) {
      pf[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= pf[i] && i * pr[j] <= MAX;
         ++j)
      pf[i * pr[j]] = pr[j];
  }
}