import youtube_dl


def download(url, options):
    with youtube_dl.YoutubeDL(options) as ydl:
        ydl.list_formats
        ydl.download([url])


def myfunc():
    print("[Python] Hello from python script!")
    url = "https://soundcloud.com/igor_kaidash/svidomij-vibir"
    options = {'listformats': True}
    download(url, options)
