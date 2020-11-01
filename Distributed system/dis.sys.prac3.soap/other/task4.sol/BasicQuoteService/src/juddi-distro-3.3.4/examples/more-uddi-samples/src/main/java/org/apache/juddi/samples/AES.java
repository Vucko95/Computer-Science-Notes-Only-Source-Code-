/*
 * Copyright 2001-2013 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
package org.apache.juddi.samples;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;


/**
 * This call is a simple test class that shows how to encrypt stuff in Java
 * using AES
 *
 * @author <a href="mailto:alexoree@apache.org">Alex O'Ree</a>
 */
public class AES {
	public static String GEN(int keysize) {
		KeyGenerator kgen;
		try {
			kgen = KeyGenerator.getInstance("AES");
			kgen.init(keysize);
			SecretKey skey = kgen.generateKey();
			byte[] raw = skey.getEncoded();
			return asHex(raw);
		} catch (Exception ex) {}
		return null;
	}

	private static String asHex(byte buf[]) {
		// return new String(buf);
		StringBuilder strbuf = new StringBuilder(buf.length * 2);
		int i;

		for (i = 0; i < buf.length; i++) {
			if (((int)buf[i] & 0xff) < 0x10) { strbuf.append("0"); }
			strbuf.append(Long.toString((int)buf[i] & 0xff, 16));
		}

		return strbuf.toString();
	}

	private static byte[] hexToBytes(String s) {
		// return s.getBytes();
		return hexToBytes(s.toCharArray());
	}
	private static final char[] kDigits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	private static byte[] hexToBytes(char[] hex) {
		int length = hex.length / 2;
		byte[] raw = new byte[length];
		for (int i = 0; i < length; i++) {
			int high = Character.digit(hex[i * 2], 16);
			int low = Character.digit(hex[i * 2 + 1], 16);
			int value = (high << 4) | low;
			if (value > 127) { value -= 256; }
			raw[i] = (byte)value;
		}
		return raw;
	}
	// default key
	// private final static String something2 = "dde284c781d60ca0b56c4b23eec85217951dc99869402abd42c7dcc9080d60aa";

	public static void main(String[] args) throws Exception {
		// ee4bd3eefe38c3d996a89589de5b9698
		String key = GEN(128);
		System.out.println(key);

		byte[] raw = hexToBytes(key); //
		SecretKeySpec skeySpec = new SecretKeySpec(raw, "AES");
		// Instantiate the cipher
		Cipher cipher = Cipher.getInstance("AES");
		cipher.init(Cipher.ENCRYPT_MODE, skeySpec);
		byte[] encrypted = cipher.doFinal("password".getBytes());
		String enc = (asHex(encrypted));
		System.out.println(enc);

		skeySpec = new SecretKeySpec(hexToBytes(key), "AES");
		cipher.init(Cipher.DECRYPT_MODE, skeySpec);
		byte[] original = cipher.doFinal(hexToBytes(enc));

		System.out.println(new String(original));
	}
}
