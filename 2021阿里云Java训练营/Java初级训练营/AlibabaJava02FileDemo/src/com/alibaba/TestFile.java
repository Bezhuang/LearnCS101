package com.alibaba;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class TestFile {

	public static void main(String[] args) throws IOException {
		// 1.�ļ�д��FileWriter, �����ļ�д����
		String file = "D:\\1.txt";
		FileWriter fileWriter = new FileWriter(file);
		for (int i = 0; i < 100; i++) {
			fileWriter.append("����Ͱ�Javaѵ��Ӫ\n");
		}
		fileWriter.flush();
		fileWriter.close();

		// 2.��ȡFileReader,�����ļ���ȡ��
		FileReader fileReader = new FileReader(file);
		char[] buffer = new char[1024];
		while (fileReader.read(buffer) > 0) {
			System.out.println(buffer);
		}
		fileReader.close();

	}

}
