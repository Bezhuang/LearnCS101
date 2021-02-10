package com.alibaba;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class TestFile {

	public static void main(String[] args) throws IOException {
		// 1.文件写入FileWriter, 创建文件写入器
		String file = "D:\\1.txt";
		FileWriter fileWriter = new FileWriter(file);
		for (int i = 0; i < 100; i++) {
			fileWriter.append("阿里巴巴Java训练营\n");
		}
		fileWriter.flush();
		fileWriter.close();

		// 2.读取FileReader,创建文件读取器
		FileReader fileReader = new FileReader(file);
		char[] buffer = new char[1024];
		while (fileReader.read(buffer) > 0) {
			System.out.println(buffer);
		}
		fileReader.close();

	}

}
