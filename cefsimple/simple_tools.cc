#include "simple_tools.h"

#include <Windows.h>
#include <cassert>
#include <fstream>
#include <map>

std::string SimpleTools::GetModuleDir()
{
	static std::string strDir = []()->std::string {
		CHAR path[MAX_PATH];
		GetModuleFileNameA(NULL, path, MAX_PATH);
		std::string strPath = path;
		size_t index = strPath.rfind('\\');
		return strPath.substr(0, index);

		}();
	return strDir;
}

std::string SimpleTools::GetResouceDir()
{
	return "E:\\cef_binary_104.4.26+g4180781+chromium-104.0.5112.102_windows32\\frontend";
}

SimpleTools::LocalFileReader::LocalFileReader()
{

}

bool SimpleTools::LocalFileReader::PreRead(const std::string& filePath)
{
	m_bytesReadPos = 0;
	size_t size = 0;
	std::ifstream file;
	file.open(filePath, std::ios::binary | std::ios::in);
	if (file.is_open())
	{
		file.seekg(0, file.end);
		size = file.tellg();
		file.seekg(0);
		m_dataBuf.resize(size, 0);
		file.read((char*)&m_dataBuf[0], size);
		formatMimeType(filePath);
		return true;
	}
	return false;
}

size_t SimpleTools::LocalFileReader::Read(void* data_out, int& bytes_to_read)
{
	if (m_bytesReadPos == m_dataBuf.size())
		return 0;
	if ((m_bytesReadPos + bytes_to_read) > m_dataBuf.size())
		bytes_to_read = m_dataBuf.size() - m_bytesReadPos;

	memcpy(data_out, &m_dataBuf[0] + m_bytesReadPos, bytes_to_read);
	m_bytesReadPos += bytes_to_read;
	return bytes_to_read;
}

std::string SimpleTools::LocalFileReader::MimeType()
{
	return m_mimeType;
}

void SimpleTools::LocalFileReader::formatMimeType(const std::string& filePath)
{
	size_t idx = filePath.find_last_of(".");
	if (idx != std::string::npos) {
		static std::map<std::string, std::string> extMimeTypeMap = {
			{"html", "text/html"},
			{"css","text/css"},
			{"js","text/javascript"}
		};
		std::string ext = filePath.substr(idx + 1);
		auto iter = extMimeTypeMap.find(ext);
		if (iter != extMimeTypeMap.end()) {
			m_mimeType = iter->second;
		}
	}
}
