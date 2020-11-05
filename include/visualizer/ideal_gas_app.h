#pragma once

#include <core/image_classifier.h>

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ideal_gas_simulator.h"

namespace idealgas {

    namespace visualizer {

        /** Allows a user to add ideal gas particles to a container and view collisions  */
        class IdealGasApp : public ci::app::App {

        private:
            /** Window Screen Margins */
            float kWindowSize = 1500.0f;
            float kMargin = 300.0f;
            //double kContainerSize = kWindowSize - kMargin;

            IdealGasSimulator simulator_;

        public:
            IdealGasApp();

            void draw() override;

            void update() override;

            //void mouseDown(ci::app::MouseEvent event) override;

            //void mouseDrag(ci::app::MouseEvent event) override;

            void keyDown(ci::app::KeyEvent event) override;
        };

    }  // namespace visualizer

}  // namespace idealgas
