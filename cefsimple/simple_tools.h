#ifndef CEF_TESTS_CEFSIMPLE_TOOLS_H_
#define CEF_TESTS_CEFSIMPLE_TOOLS_H_

#include <string>
#include <vector>

namespace SimpleTools
{
	std::string GetModuleDir();

	std::string GetResouceDir();

	class LocalFileReader
	{
	public:
		LocalFileReader();
		bool PreRead(const std::string& filePath);
		size_t Read(void* data_out, int& bytes_to_read);
		std::string MimeType();
	private:
		void formatMimeType(const std::string& filePath);

		size_t m_bytesReadPos = 0;
		std::vector<char> m_dataBuf;
		std::string m_mimeType;
	};

}

#endif //CEF_TESTS_CEFSIMPLE_TOOLS_H_