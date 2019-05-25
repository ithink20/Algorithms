import re

def encrypt_text(text, shift):
	encrypted_text = ""
	for i in range(len(text)):
		if (re.match('[^A-Za-z0-9]', text[i]) != None):
			encrypted_text += text[i]
			continue
		if text[i].isupper():
			encrypted_text += chr((ord(text[i]) + shift - 65) % 26 + 65)
		else:
			encrypted_text += chr((ord(text[i]) + shift - 97) % 26 + 97)
	return encrypted_text


def main():
	text = raw_input("Enter text here:")
	shift = input("Enter shift : ")
	print encrypt_text(text, shift)

	#to decrypt_cyper : call encrypt_text(text, 26 - shift)



if __name__ == '__main__':
	main()
