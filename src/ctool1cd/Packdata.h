/*
 * Packdata.h
 *
 *  Created on: 2 окт. 2017 г.
 */

#ifndef SRC_CTOOL1CD_PACKDATA_H_
#define SRC_CTOOL1CD_PACKDATA_H_

#include <System.Classes.hpp>
#include <boost/filesystem.hpp>
#include <array>
#include <memory>

#include "TempStream.h"
#include "Constants.h"

// Структура одной записи индекса упакованных объектов хранилища 8.3 (из файла *.ind)

#pragma pack(push)
#pragma pack(1)
struct record_data_hash
{
	char datahash[DATAHASH_FIELD_LENGTH];	// хэш файла
	int64_t offset;		// смещение файла в файле *.pck
};
#pragma pack(pop)

// Класс для одной пары файлов *.ind и *.pck в каталоге data\pack\ хранилища 8.3

class Packdata {
public:

	explicit Packdata(boost::filesystem::path& file_path);
	~Packdata();

	TStream* get_data(const char* datahash, bool &find);
private:
	std::unique_ptr<TFileStream> pack;	// открытый на чтение файл *.pck
	std::vector<record_data_hash> datahashes;

};

#endif /* SRC_CTOOL1CD_PACKDATA_H_ */
