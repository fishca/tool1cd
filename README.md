# Tool 1CD

Полезный инструмент для работы с файлами 1CD за авторством Валерия Агеева с адаптацией от сообщества.

## Установка

Проект в процессе разработки.

Последние тестовые сборки можно получать через публичные CI-сервера:

 * [Win32](https://ci.appveyor.com/api/projects/dmpas/tool1cd/artifacts/Release%2Fctool1cd.exe?branch=develop)
 * [Ubuntu](https://launchpad.net/~dmpas/+archive/ubuntu/e8):
```sh
sudo add-apt-repository ppa:dmpas/e8
sudo apt-get update
sudo apt-get install ctool1cd
```

## Сборка

см. [BUILD.md](BUILD.md)

## Использование

 `-l, -logfile <файл>`
   записывать все сообщения программы в текстовый лог-файл. Если файл существует, он перезаписывается. Кодировка файла UTF8

 `-ne, -NotExclusively`
   открыть базу не монопольно (Это небезопасно, возможны ошибки!).

 `-eax, -ExportAllToXML <путь>`
   экспортировать по указанному пути все таблицы в XML.

 `-ex, -ExportToXML <путь> <список>`
   экспортировать по указанному пути указанные таблицы в XML.
   В списке через запятую, точку с запятой или пробел указывается список имен экспортируемых таблиц. Можно использовать знаки подстановки * и ?
   Если в списке содержатся пробелы, список необходимо заключать в кавычки.

 `-bf, -BlobToFile [yes/no]`
   при экспорте в XML выгружать BLOB в отдельные файлы.
   По умолчанию BLOB в отдельные файлы не выгружается.

 `-pb, -ParseBlob [yes/no]`
   при экспорте в XML и выгрузке BLOB в отдельные файлы по-возможности распаковывать данные BLOB.
   По умолчанию BLOB при выгрузке в отдельные файлы распаковываются.

 `-dc, -DumpConfig <путь>`
   Выгрузить основную конфигурацию по указанному пути.

 `-ddc, -DumpDBConfig <путь>`
   Выгрузить конфигурацию базы данных по указанному пути.

 `-dvc, -DumpVendorsConfigs <путь>`
   Выгрузить конфигурации поставщиков информационной базы по указанному пути.

 `-dac, -DumpAllConfigs <путь>`
   Выгрузить все конфигурации информационной базы по указанному пути.

 `-drc, -DumpDepotConfig <номер версии> <путь>`
   Выгрузить конфигурацию хранилища заданной версии по указанному пути.
   Номер версии - это целое число. 1, 2, 3 и т.д. - выгрузить конфигурацию указанной версии, 0 - выгрузить последнюю версию, -1 - предпоследнюю и т.д.

 `-dpc, -DumpPartDepotConfig <номер версии>[:<номер версии>] <путь>`
   Выгрузить частично файлы конфигурации хранилища заданной версии (или заданного диапазона версий) по указанному пути.
   Номер версии - это целое число. 1, 2, 3 и т.д. - выгрузить файлы указанной версии, 0 - выгрузить файлы последней версии, -1 - предпоследней и т.д.

 `-eb, -ExportToBinary <путь> <список>`
   Экспортировать по указанному пути указанные таблицы.
   В списке через запятую, точку с запятой или пробел указывается список имён экспортируемых таблиц. Можно использовать знаки подстановки * и ?
   Если в списке содержатся пробелы, список необходимо заключать в кавычки.

 `-ib, -ImportFromBinary <путь> <список>`
   Импортировать по указанному пути указанные таблицы.
   В списке через запятую, точку с запятой или пробел указывается список имён импортируемых таблиц. Можно использовать знаки подстановки * и ?
   Если в списке содержатся пробелы, список необходимо заключать в кавычки.
   Таблицы должны существовать в базе, новые таблицы не создаются.

 `-slo, -SaveLostObjects <путь>`
   Найти потерянные объекты и сохранить.

Если в пути содержатся пробелы, его необходимо заключать в кавычки. Пути следует указывать без завершающего слеша `/` и бэкслеша `\`
Для команд `-dc`, `-ddc`, `-drc` вместо пути можно указывать имя файла конфигурации (имя файла должно заканчиваться на `.cf`).
