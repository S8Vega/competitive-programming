# competitive-programming

¡Bienvenido a mi repositorio de programación competitiva! Aquí encontrarás una colección de algoritmos y soluciones a problemas que he abordado en diversas plataformas de competición como Codeforces, LeetCode, HackerRank, RPC, Codeo y competiciones oficiales de ICPC.

## Estructura del Repositorio

- **algorithms**: Esta carpeta contiene un template que suelo utilizar para C++, junto con diversos algoritmos implementados en el lenguaje.

- **problems**: Aquí encontrarás las soluciones a los problemas que he resuelto en distintas plataformas. Las soluciones están organizadas por plataforma y categorizadas según el tipo de problema.

## Cómo Contribuir

Siéntete libre de contribuir al repositorio de la siguiente manera:

1. **Añadir nuevos algoritmos**: Si tienes implementaciones de algoritmos que no están en la carpeta `algorithms`, ¡agrégalas! Asegúrate de incluir comentarios descriptivos y ejemplos de uso.

2. **Contribuir a soluciones de problemas**: Si tienes soluciones más eficientes o diferentes enfoques para problemas existentes, o si encuentras algún problema sin resolver, ¡no dudes en contribuir!

3. **Mejorar el template C++**: Si tienes sugerencias para mejorar el template en la carpeta `algorithms`, tus contribuciones son bienvenidas.

## C++ Compilation and Execution Commands

Para compilar y ejecutar los algoritmos y soluciones de problemas, puedes utilizar los siguientes comandos:

Ejecucion de un archivo:
```bash
g++ -pthread -Wall -Wshadow -std=c++17 -o main main.cpp && ./main < main.txt
freopen("input.in", "r" , stdin);
freopen("output.out", "w", stdout);
```

Ejecucion de un archivo con code-runner.executorMap en VSCode:
```bash
cd $dir && g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra -o main $fileName && main < $fileNameWithoutExt.txt
```

Ejecucion de un archivo con testcases en Linux:
```bash
g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra -D_GLIBCXX_DEBUG -o main main.cpp && for x in main*.txt; do echo ====================$x=================; time -p ./main <$x; echo ===========================================; done
```

Ejecucion de un archivo en windows powershell:
```bash
cd $dir && g++ -DLOCAL -std=c++17 -g -O2 -Wconversion -Wshadow -Wall -Wextra -o main $fileName && $testcase = '>>> name'; foreach ($file in Get-ChildItem $fileNameWithoutExt*.txt) { echo $testcase.Replace('name', $file.Name); Get-Content $file.Name | ./main; echo ==========================================; }
```

## Plataformas de Competición

- [Codeforces](https://codeforces.com/)
- [LeetCode](https://leetcode.com/)
- [HackerRank](https://www.hackerrank.com/)
- [RPC (Red de Programación Competitiva)](https://redprogramacioncompetitiva.com/)
- [Codeo](https://www.codeo.app/)
- Competiciones oficiales de [ICPC](https://icpc.global/)

## Notas Importantes

- Asegúrate de leer y comprender el código antes de utilizarlo en competiciones.
- Las soluciones pueden tener diferentes niveles de eficiencia. Algunas están diseñadas para ser educativas y comprensibles, mientras que otras priorizan la velocidad.

¡Espero que encuentres útiles las implementaciones y soluciones en este repositorio! Si tienes preguntas, problemas o mejoras, no dudes en abrir un issue o enviar un pull request.
