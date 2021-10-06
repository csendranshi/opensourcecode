def matrix_rotation(matrix):
    L = 0
    R = len(matrix)-1

    while L < R:
        for i in range(L, R):
            temp = matrix[L][i]
            matrix[L][i] = matrix[R-i+L][L]
            matrix[R-i+L][L] = matrix[R][R-i+L]
            matrix[R][R-i+L] = matrix[i][R]
            matrix[i][R] = temp
        L += 1
        R -= 1
    return matrix


if __name__ == "__main__":
    matrices = [[[0, 1, 2, 3], [4, 5, 6, 7], [8, 9, 10, 11], [12, 13, 14, 15]], [[0, 1, 2], [3, 4, 5], [6, 7, 8]], [
        [0, 1, 2, 3, 4], [5, 6, 7, 8, 9], [10, 11, 12, 13, 14], [15, 16, 17, 18, 19], [20, 21, 22, 23, 24]]]
    for matrix in matrices:
        rotated = rotate_matrix(matrix)
        for row in rotated:
            print(row)
        print()
