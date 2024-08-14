# build
```bash
$ ./gradlew build
```

# run
```bash
java -Xmx10G -Xms10G -Djava.library.path=jni/build/lib/main/debug/ -jar app/build/libs/app.jar 10000000
```

