class SubModel {
    constructor(model, shader, material, vertices, indices) {
        const gl = shader.gl;
        const nrms = [];
        const vtxs = [];
        const componentNames = shader.getVertexComponentNames();

        this.model = model;
        this.shader = shader;
        this.material = material;

        this.nrmBuffer = gl.createBuffer();
        this.vtxBuffer = gl.createBuffer();
        this.idxBuffer = gl.createBuffer();

        this.nrmBuffer.vtxCount = 0;
        this.vtxBuffer.vtxCount = vertices.length;

        this.min = new Vector1x4(vertices[0].x, vertices[0].y, vertices[0].z);
        this.max = new Vector1x4(vertices[0].x, vertices[0].y, vertices[0].z);

        for (let v of vertices) { 
            componentNames.forEach(name => vtxs.push(v[name]));

            if (v.hasOwnProperty('nx')) {
                // model space vertex normal start
                nrms.push(v.x); // p0.x
                nrms.push(v.y); // p0.y 
                nrms.push(v.z); // p0.z
                nrms.push(0.0); nrms.push(0.0); nrms.push(1.0); nrms.push(1.0); // blue
                
                // model space vertex normal end
                nrms.push(v.x + v.nx * SubModel.NORMAL_SCALE); // p1.x
                nrms.push(v.y + v.ny * SubModel.NORMAL_SCALE); // p1.y
                nrms.push(v.z + v.nz * SubModel.NORMAL_SCALE); // p1.z
                nrms.push(0.0); nrms.push(0.0); nrms.push(1.0); nrms.push(1.0); // blue

                this.nrmBuffer.vtxCount += 2;
            }

            if (v.hasOwnProperty('bx')) {
                // model space vertex normal start
                nrms.push(v.x); // p0.x
                nrms.push(v.y); // p0.y
                nrms.push(v.z); // p0.z
                nrms.push(0.0); nrms.push(1.0); nrms.push(0.0); nrms.push(1.0); // green

                // model space vertex normal end
                nrms.push(v.x + v.bx * SubModel.BINORMAL_SCALE); // p1.x
                nrms.push(v.y + v.by * SubModel.BINORMAL_SCALE); // p1.y
                nrms.push(v.z + v.by * SubModel.BINORMAL_SCALE); // p1.z
                nrms.push(0.0); nrms.push(1.0); nrms.push(0.0); nrms.push(1.0); // green

                // model space vertex normal start
                nrms.push(v.x); // p0.x
                nrms.push(v.y); // p0.y
                nrms.push(v.z); // p0.z
                nrms.push(1.0); nrms.push(0.0); nrms.push(0.0); nrms.push(1.0); // red

                // model space vertex normal end
                nrms.push(v.x + (v.by * v.nz - v.bz * v.ny) * SubModel.TANGENT_SCALE); // p1.x
                nrms.push(v.y + (v.bz * v.nx - v.bx * v.nz) * SubModel.TANGENT_SCALE); // p1.y
                nrms.push(v.z + (v.bx * v.ny - v.by * v.nx) * SubModel.TANGENT_SCALE); // p1.z
                nrms.push(1.0); nrms.push(0.0); nrms.push(0.0); nrms.push(1.0); // red

                this.nrmBuffer.vtxCount += 4;
            }

            // recalculate model space bounding box
            if (v.x < this.min.x) { this.min.x = v.x; } else if (v.x > this.max.x) { this.max.x = v.x; }
            if (v.y < this.min.y) { this.min.y = v.y; } else if (v.y > this.max.y) { this.max.y = v.y; }
            if (v.z < this.min.z) { this.min.z = v.z; } else if (v.z > this.max.z) { this.max.z = v.z; }
        }

        gl.bindBuffer(gl.ARRAY_BUFFER, this.nrmBuffer);
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(nrms), gl.STATIC_DRAW);

        gl.bindBuffer(gl.ARRAY_BUFFER, this.vtxBuffer);
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vtxs), gl.STATIC_DRAW);

        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.idxBuffer);
        gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint16Array(indices), gl.STATIC_DRAW);
    }

    drawPrimitives(noAlpha) {
        if (noAlpha || !this.material.isTranslucent()) {
            this.shader.drawPrimitives(this);
        } else {
            SubModel.translucents.push(this);
            this.depth = 0.0;
        }
    }

    drawAllNormals() {
        /*
        const shaderP3C4 = Shader.map.get('P3C4');
        shaderP3C4.drawPrimitives(this);
        */
    }

    static drawTranslucents() {
        // sort translucents by bounding box center z in projection space
        SubModel.translucents.forEach(subModel => subModel.shader.drawPrimitives(subModel));
        SubModel.translucents.length = 0;
    }
}

SubModel.translucents   = [];
SubModel.NORMAL_SCALE   = 0.25;
SubModel.TANGENT_SCALE  = 0.25;
SubModel.BINORMAL_SCALE = 0.25;

class Model extends RefFrame {
    constructor(parent) {
        super(parent);
        this.subModels = [];
    }

    addSubModel(shader, material, vertices, indices) {
        this.subModels.push(new SubModel(this, shader, material, vertices, indices));
    }

    draw(noAlpha) {
        this.subModels.forEach(subModel => subModel.drawPrimitives(noAlpha));
    }

    drawNormals() {
        this.subModels.forEach(subModel => subModel.drawAllNormals());
    }
}

