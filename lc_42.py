def trap(height):
    stack = []
    w = 0
    for i in range(len(height)):
        while stack and height[i] > height[stack[i-1]]:
            bottom = stack.pop()
            if not stack:
                break
            left = stack[-1]
            w = i - left - 1
            h = min(height[left], height[i]) - height[bottom]
            wt = w * h
        stack.append(i)
    
    return wt

height = [3, 0, 0, 2, 0, 4]
ans = trap(height)
print(ans)