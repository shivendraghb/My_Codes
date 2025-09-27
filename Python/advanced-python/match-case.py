def http_status(status):
    match status:
        case 200:
            return "ok"
        case 404:
            return "not found"
        case 500:
            return "internal server error"
        case _:
            return "unknown status"

print(http_status(200))  # ok
print(http_status(404))  # not found
print(http_status(500))  # internal server error
print(http_status(123))  # unknown status
