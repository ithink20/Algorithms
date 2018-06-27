import os

def list_files(path_to_file):
    for root, directories, filenames in os.walk(path_to_file):
        level = root.replace(path_to_file, '').count(os.sep)
        indent = ' ' * 4 * (level)
        print('{}{}/'.format(indent, os.path.basename(root)))
        subindent = ' ' * 4 * (level + 1)
        for filename in filenames:
            print('{}{}'.format(subindent, filename))

def main():
    path_to_file = '/Users/vikaschaurasiya/Desktop'
    list_files(path_to_file)


if __name__ == '__main__':
    main()
