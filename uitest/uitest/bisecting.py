# -*- tab-width: 4; indent-tabs-mode: nil; py-indent-offset: 4 -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

from functools import wraps

def requires(revision):
    def decorator(f):
        f.requires = revision
        return f
    return decorator

# vim: set shiftwidth=4 softtabstop=4 expandtab:
