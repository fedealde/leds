# Testing de Software en Sistemas Embebidos - CESE UBA
## Trabajo Práctico N°2

>Autor: Federico Alderisi

Desarrollo de HAL de puerto de LEDs y testing unitario de cada funcionalidad.

### Tests

Tests desarrollados:

```
1- Inicializacion de puerto
2- Prender un LED individual
3- Apagar un LED individual
4- Prender y apagar varios LEDs
5- Apagar TODOS los LEDs
6- Encender TODOS los LEDs
7- Consultar por un LED encendido
8- Consultar por un LED apagado
9- Consultar por limite de parametro LED
10- Consultar por LED por fuera de los limites
11- Verificar creacion de puerto nulo
12- Prueba de encendido (2 y 5) y apagado (3 y 5), dentro y fuera de limites (-6), chequeo final de leds encendidos (2)
```

### Resultados

```bash
ceedling clobber gcov:all utils:gcov
```
```
Clobbering all generated files...
(For large projects, this task may take a long time to complete)



Test 'test_leds.c'
------------------
Generating runner for test_leds.c...
Compiling test_leds_runner.c...
Compiling test_leds.c...
Compiling leds.c with coverage...
Compiling unity.c...
Compiling cmock.c...
Linking test_leds.out...
Running test_leds.out...
Creating gcov results report(s) in 'build/artifacts/gcov'... Done in 0.568 seconds.

--------------------------
GCOV: OVERALL TEST SUMMARY
--------------------------
TESTED:  12
PASSED:  12
FAILED:   0
IGNORED:  0


---------------------------
GCOV: CODE COVERAGE SUMMARY
---------------------------
leds.c Lines executed:100.00% of 23
leds.c Branches executed:100.00% of 10
leds.c Taken at least once:100.00% of 10
leds.c Calls executed:100.00% of 6
leds.c Lines executed:100.00% of 23
```

### First steps

Luego de instalar los framewors utilizando los siguientes pasos:

- Instalación de Ruby
`sudo apt-get install ruby gcovr`
- Instalación de Ceedling
`sudo gem install ceedling`
- Creación del repositorio de trabajo
`git init project_name`
- Creación del proyecto ceedling
`ceedling new project_name`

Versiones de framework:

`ruby -v`
ruby 3.0.2p107 (2021-07-07 revision 0db68f0233) [x86_64-linux-gnu]
`ceedling version`
>Welcome to Ceedling!
    Ceedling:: 0.31.1
       CMock:: 2.5.4
       Unity:: 2.5.4
  CException:: 1.3.3
