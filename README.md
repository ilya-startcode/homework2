# cmake-example-repo

| **CI Service** | Build Status |
|:---------------|-------------:|
| GitHub Actions | [![Build Status (GitHub Actions)](https://github.com/ilya-startcode/homework2/blob/main/.github/workflows/example-tests.yml)]https://github.com/ilya-startcode/homework2/blob/main/.github/workflows/example-tests.yml |

Примеры гуглтестов [Google Test](https://code.google.com/p/googletest)

## Сборка

После того как склонировали, собирите:
bash
```
cmake -S . -B mybuild
cd mybuild
cmake --build .
```

Запустить тесты:
```
ctest
```
