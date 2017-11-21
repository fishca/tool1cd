/*
 * TableFileStream.h
 *
 *  Created on: 24 июн. 2017 г.
 *
 */

#ifndef SRC_CTOOL1CD_TABLEFILESTREAM_H_
#define SRC_CTOOL1CD_TABLEFILESTREAM_H_

#include <vector>

#include "Common.h"
#include "Table.h"

//---------------------------------------------------------------------------
// Класс таблицы контейнера файлов (CONFIG, CONFIGSAVE, PARAMS, FILES, CONFIGCAS, CONFIGCASSAVE)
// https://its.1c.ru/db/metod8dev#content:1798:hdoc
// CONFIG        - (конфигурация базы данных)
// CONFIGSAVE    - (сохраненная конфигурация)
// CONFIGCAS     - (системное хранилище конфигураций расширений)
// CONFIGCASSAVE - (сохраненное системное хранилище конфигураций расширений)
// FILES         - (работа с хранилищем конфигурации, профайлы и т.п.)
// PARAMS        - (служебные параметры информационной базы)
//
// Все они имеют одинаковый набор полей :
//
// FileName   - имя файла;
// Creation   - момент времени создания файла;
// Modified   - момент времени последней модификации файла;
// Attributes - атрибуты файла;
// DataSize   - длина файла в байтах;
// BinaryData - данные, хранимые в файле.

class TableFileStream : public TStream
{
private:
	int64_t curoffset;
	table_file* tablefile;
	TStream** streams;
public:
	TableFileStream(table_file* tf);
	virtual ~TableFileStream();

	virtual int64_t Read(void *Buffer, int64_t Count) override;
	virtual int32_t Read(std::vector<System::t::Byte> Buffer, int32_t Offset, int32_t Count);
	virtual int64_t Write(const void *Buffer, int64_t Count) override { throw(Exception(L"Write read-only stream")); }
	virtual int32_t Write(const std::vector<System::t::Byte> Buffer, int32_t Offset, int32_t Count) { throw(Exception(L"Write read-only stream")); }
	virtual int32_t Seek(int32_t Offset, System::Word Origin);
	virtual int64_t Seek(const int64_t Offset, TSeekOrigin Origin) override;
};


#endif /* SRC_CTOOL1CD_TABLEFILESTREAM_H_ */
