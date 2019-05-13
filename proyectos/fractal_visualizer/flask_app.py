import os, re
from flask import Flask, render_template, abort, send_file

app = Flask(__name__)
@app.route('/', defaults={'req_path': ''})
@app.route('/<path:req_path>')

def dir_listing(req_path):
    BASE_DIR = '/home/samosapiens/fractals_visualizer/'

    # Joining the base and the requested path
    abs_path = os.path.join(BASE_DIR, req_path)

    # Return 404 if path doesn't exist
    if not os.path.exists(abs_path):
        return abort(404)

    # Check if path is a file and serve
    if os.path.isfile(abs_path):
        return send_file(abs_path)

    # Show directory contents
    files = [f for f in os.listdir(abs_path) if '.html' in f[-5:]]
    return render_template('files.html', files=files)