/* ===== 23e7eaea0 workers.fishing.memory_fish_read:126 ===== */
/* ghidra_name=FUN_23e7eaea0 entry=23e7eaea0 size=14564 */

longlong * FUN_23e7eaea0(longlong param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  bool bVar5;
  undefined1 auVar6 [16];
  char cVar7;
  int iVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong *plVar11;
  longlong *plVar12;
  code *pcVar13;
  code *pcVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong lVar20;
  longlong *plVar21;
  code *pcVar22;
  undefined4 uVar23;
  longlong *plVar24;
  longlong *in_R11;
  longlong *unaff_R12;
  longlong lVar25;
  undefined8 uVar26;
  longlong *local_160;
  longlong *local_158;
  longlong *local_150;
  code *local_148;
  longlong *local_138;
  undefined1 local_f8 [16];
  code *local_e8 [2];
  undefined1 local_d8 [16];
  code *local_c8 [2];
  undefined1 local_b8 [16];
  code *local_a8;
  longlong *local_98;
  code *pcStack_90;
  code *local_88;
  undefined8 local_80;
  undefined8 local_78;
  
  plVar24 = DAT_23eedeb08;
  local_a8 = (code *)0x0;
  local_b8 = (undefined1  [16])0x0;
  if (DAT_23eedeb08 == (longlong *)0x0) {
LAB_23e7eaf07:
    DAT_23eedeb08 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedeb00,DAT_23eedebc0,0x38);
  }
  else {
    lVar20 = *DAT_23eedeb08;
    if (1 < lVar20) {
      *DAT_23eedeb08 = lVar20 + -1;
      goto LAB_23e7eaf07;
    }
    if (DAT_23eedeb08[2] != 0) {
      *DAT_23eedeb08 = lVar20 + -1;
      if (lVar20 + -1 == 0) {
        (**(code **)(plVar24[1] + 0x30))(plVar24);
      }
      goto LAB_23e7eaf07;
    }
  }
  plVar3 = DAT_23eedeb08;
  lVar20 = *(longlong *)(param_1 + 0x38);
  lVar9 = *(longlong *)(lVar20 + 8);
  plVar24 = DAT_23eedeb08 + 9;
  DAT_23eedeb08[0xf] = lVar9;
  *(longlong **)(lVar20 + 8) = plVar24;
  if ((lVar9 != 0) &&
     (((*(char *)(lVar9 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar9 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar9 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar9 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar24 = *(longlong **)(lVar9 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar24;
    if (plVar24 != (longlong *)0x0) {
      *plVar24 = *plVar24 + 1;
    }
  }
  local_80 = DAT_23eedddd0;
  local_98 = DAT_23eedddc8;
  plVar24 = (longlong *)&DAT_23ed6a498;
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  local_78 = DAT_23ed6ccf0;
  *(undefined4 *)(plVar3 + 5) = 0x82;
  local_88 = _Py_NoneStruct_exref;
  pcStack_90 = DAT_23eeddba8;
  if (DAT_23ed6a498 != (longlong *)0x0) {
LAB_23e7eaffd:
    plVar24 = (longlong *)FUN_23e95b390(param_1,DAT_23ed6a498,&local_98);
    if (plVar24 != (longlong *)0x0) {
      if (((code *)plVar24[1] == PyModule_Type_exref) ||
         (iVar8 = PyType_IsSubtype(), uVar10 = DAT_23eedddd8, iVar8 != 0)) {
        uVar26 = DAT_23eedddd8;
        pcVar14 = DAT_23eeddba8;
        uVar10 = DAT_23ed6ccf0;
        local_160 = (longlong *)PyObject_GetAttr(plVar24,DAT_23eedddd8);
        if (local_160 != (longlong *)0x0) goto LAB_23e7eb09c;
        local_160 = (longlong *)FUN_23e970390(param_1,plVar24,pcVar14,uVar26,uVar10);
LAB_23e7ebc3b:
        *plVar24 = *plVar24 + -1;
        if (*plVar24 == 0) {
          (**(code **)(plVar24[1] + 0x30))(plVar24);
        }
        if (local_160 == (longlong *)0x0) goto LAB_23e7ebc52;
      }
      else {
        local_160 = (longlong *)PyObject_GetAttr(plVar24,DAT_23eedddd8);
        if (local_160 == (longlong *)0x0) {
          local_160 = (longlong *)FUN_23e8d2cf0(param_1,plVar24,uVar10);
          goto LAB_23e7ebc3b;
        }
LAB_23e7eb09c:
        *plVar24 = *plVar24 + -1;
        if (*plVar24 == 0) {
          (**(code **)(plVar24[1] + 0x30))(plVar24);
        }
      }
      plVar24 = (longlong *)FUN_23e8bc2f0(local_160,DAT_23eeddde0);
      if (plVar24 != (longlong *)0x0) {
        *(undefined4 *)(plVar3 + 5) = 0x83;
        plVar11 = (longlong *)FUN_23e91a870(param_1,plVar24);
        *plVar24 = *plVar24 + -1;
        if (*plVar24 == 0) {
          (**(code **)(plVar24[1] + 0x30))(plVar24);
        }
        if (plVar11 != (longlong *)0x0) {
          plVar24 = (longlong *)FUN_23ebf7180(plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          lVar20 = DAT_23ed6cce8;
          if (plVar24 != (longlong *)0x0) {
            lVar9 = *(longlong *)(param_1 + 0x10);
            plVar11 = *(longlong **)(DAT_23ed6cce8 + 0x20);
            iVar8 = *(int *)(lVar9 + 0x1410);
            *plVar11 = *plVar11 + 1;
            if (iVar8 == 0) {
              plVar12 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
              plVar11 = *(longlong **)(lVar20 + 0x20);
            }
            else {
              iVar8 = iVar8 + -1;
              *(int *)(lVar9 + 0x1410) = iVar8;
              plVar12 = *(longlong **)(lVar9 + 0x1190 + (longlong)iVar8 * 8);
              *plVar12 = 1;
            }
            lVar20 = *(longlong *)(lVar20 + 0x28);
            plVar12[2] = 0;
            plVar12[3] = 1;
            plVar12[4] = (longlong)plVar11;
            plVar12[5] = lVar20;
            local_150 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            plVar16 = (longlong *)0x0;
            while( true ) {
              pcVar14 = *(code **)(plVar24[1] + 0xe0);
              if (pcVar14 == (code *)0x0) break;
              plVar15 = (longlong *)(*pcVar14)(plVar24);
              if (plVar15 == (longlong *)0x0) goto LAB_23e7ec42a;
              if ((local_150 != (longlong *)0x0) && (*local_150 = *local_150 + -1, *local_150 == 0))
              {
                (**(code **)(local_150[1] + 0x30))(local_150);
              }
              plVar21 = (longlong *)FUN_23a388310(plVar15);
              local_150 = plVar15;
              if (plVar21 == (longlong *)0x0) {
                lVar20 = *(longlong *)(param_1 + 0x60);
                uVar10 = *(undefined8 *)(param_1 + 0x68);
                pcVar14 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                goto LAB_23e7ec5ec;
              }
              plVar15 = (longlong *)(**(code **)(plVar21[1] + 0xe0))(plVar21);
              if ((plVar15 == (longlong *)0x0) &&
                 (plVar15 = (longlong *)FUN_23a3c1b70(param_1,local_b8,0,2),
                 plVar15 == (longlong *)0x0)) {
                lVar9 = *plVar21;
                plVar17 = (longlong *)0x0;
LAB_23e7ec54f:
                pcVar14 = local_a8;
                lVar20 = local_b8._0_8_;
                uVar10 = local_b8._8_8_;
                local_b8 = (undefined1  [16])0x0;
                local_a8 = (code *)0x0;
                *plVar21 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar21[1] + 0x30))(plVar21);
                }
                local_a8 = (code *)0x0;
                local_b8 = (undefined1  [16])0x0;
                if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                goto LAB_23e7ec5ec;
              }
              plVar17 = (longlong *)(**(code **)(plVar21[1] + 0xe0))(plVar21);
              if ((plVar17 == (longlong *)0x0) &&
                 (plVar17 = (longlong *)FUN_23a3c1b70(param_1,local_b8,1,2),
                 plVar17 == (longlong *)0x0)) {
                lVar9 = *plVar21;
                goto LAB_23e7ec54f;
              }
              cVar7 = FUN_23a3884a0(param_1,local_b8,plVar21,2);
              lVar9 = *plVar21;
              if (cVar7 == '\0') goto LAB_23e7ec54f;
              *plVar21 = lVar9 + -1;
              if (lVar9 + -1 == 0) {
                (**(code **)(plVar21[1] + 0x30))(plVar21);
              }
              lVar20 = *plVar15;
              *plVar15 = lVar20 + 1;
              if (plVar11 != (longlong *)0x0) {
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                lVar20 = *plVar15 + -1;
              }
              *plVar15 = lVar20;
              if (lVar20 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              lVar20 = *plVar17;
              *plVar17 = lVar20 + 1;
              if (plVar16 != (longlong *)0x0) {
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                lVar20 = *plVar17 + -1;
              }
              *plVar17 = lVar20;
              if (lVar20 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              iVar8 = PyDict_SetItem(plVar12,plVar17);
              plVar11 = plVar15;
              plVar16 = plVar17;
              if (iVar8 != 0) {
                lVar20 = *(longlong *)(param_1 + 0x60);
                uVar10 = *(undefined8 *)(param_1 + 0x68);
                goto LAB_23e7ec293;
              }
              lVar9 = *(longlong *)(param_1 + 0x10);
              if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) != 0) ||
                   (*(int *)(lVar9 + 0x78) != 0)) && (iVar8 = Py_MakePendingCalls(), iVar8 < 0)) &&
                 (lVar20 = *(longlong *)(param_1 + 0x60), lVar20 != 0)) goto LAB_23e7ec28a;
              if (*(int *)(lVar9 + 0x68) == 0) {
                plVar15 = *(longlong **)(param_1 + 0x90);
              }
              else {
                PyEval_SaveThread();
                PyEval_AcquireThread(param_1);
                plVar15 = *(longlong **)(param_1 + 0x90);
              }
              if (plVar15 != (longlong *)0x0) goto LAB_23e7ec21f;
            }
            PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                         *(undefined8 *)(plVar24[1] + 0x18));
LAB_23e7ec42a:
            cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
            if (cVar7 == '\0') {
              lVar20 = *(longlong *)(param_1 + 0x60);
              uVar10 = *(undefined8 *)(param_1 + 0x68);
              pcVar14 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e7ec5ec;
            }
            *plVar12 = *plVar12 + 1;
            lVar20 = *plVar24;
            *plVar24 = lVar20 + -1;
            if (lVar20 + -1 == 0) {
              (**(code **)(plVar24[1] + 0x30))(plVar24);
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if ((local_150 != (longlong *)0x0) && (*local_150 = *local_150 + -1, *local_150 == 0)) {
              (**(code **)(local_150[1] + 0x30))(local_150);
            }
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            local_150 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            in_R11 = (longlong *)0x0;
            plVar24 = (longlong *)0x0;
            local_158 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            goto LAB_23e7eba6f;
          }
        }
      }
      pcVar14 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      lVar20 = *(longlong *)(param_1 + 0x60);
      uVar10 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e7eb389;
    }
LAB_23e7ebc52:
    local_b8._0_8_ = *(longlong *)(param_1 + 0x60);
    local_a8 = *(code **)(param_1 + 0x70);
    uVar23 = 0x82;
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_160 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    local_b8._8_8_ = *(undefined8 *)(param_1 + 0x68);
    goto LAB_23e7eb39f;
  }
  plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
  if (plVar11 != (longlong *)0x0) {
    *plVar11 = *plVar11 + 1;
    DAT_23ed6a498 = plVar11;
    goto LAB_23e7eaffd;
  }
  PyErr_PrintEx(0);
  Py_Exit();
LAB_23e7ed9f8:
  local_b8 = *(undefined1 (*) [16])(param_1 + 0x60);
  local_a8 = *(code **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *unaff_R12 = (longlong)plVar11;
  if (plVar11 == (longlong *)0x0) {
    (**(code **)(unaff_R12[1] + 0x30))();
    in_R11 = local_158;
  }
  if (local_a8 != (code *)0x0) {
    if (plVar3 == *(longlong **)(local_a8 + 0x18)) goto LAB_23e7edbf0;
    local_150 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    local_138 = (longlong *)0x0;
    iVar8 = 0x8a;
    local_158 = (longlong *)0x0;
    goto LAB_23e7ebd40;
  }
LAB_23e7edc1d:
  local_150 = (longlong *)0x0;
  plVar11 = (longlong *)0x0;
  local_138 = (longlong *)0x0;
  iVar8 = 0x8a;
  local_158 = (longlong *)0x0;
  goto LAB_23e7ec830;
LAB_23e7ec21f:
  plVar21 = *(longlong **)(param_1 + 0x60);
  plVar17 = *(longlong **)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x90) = 0;
  plVar18 = *(longlong **)(param_1 + 0x70);
  *(longlong **)(param_1 + 0x60) = plVar15;
  *plVar15 = *plVar15 + 1;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
    (**(code **)(plVar21[1] + 0x30))();
  }
  if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  if ((plVar18 == (longlong *)0x0) || (*plVar18 = *plVar18 + -1, *plVar18 != 0)) {
    lVar20 = *(longlong *)(param_1 + 0x60);
  }
  else {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
    lVar20 = *(longlong *)(param_1 + 0x60);
  }
LAB_23e7ec28a:
  uVar10 = *(undefined8 *)(param_1 + 0x68);
LAB_23e7ec293:
  pcVar14 = *(code **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7ec5ec:
  local_a8 = (code *)0x0;
  local_b8 = (undefined1  [16])0x0;
  lVar9 = *plVar24;
  *plVar24 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar24[1] + 0x30))(plVar24);
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((local_150 != (longlong *)0x0) &&
     (lVar9 = *local_150, *local_150 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_150[1] + 0x30))(local_150);
  }
  local_a8 = (code *)0x0;
  local_b8 = (undefined1  [16])0x0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
LAB_23e7eb389:
  uVar23 = 0x83;
  local_a8 = pcVar14;
  local_b8._0_8_ = lVar20;
  local_b8._8_8_ = uVar10;
LAB_23e7eb39f:
  pcVar14 = local_a8;
  local_d8._8_8_ = local_b8._8_8_;
  local_d8._0_8_ = local_b8._0_8_;
  local_a8 = (code *)0x0;
  plVar24 = *(longlong **)(param_1 + 0x138);
  local_b8 = (undefined1  [16])0x0;
  local_c8[0] = pcVar14;
  if (plVar24 != (longlong *)0x0) {
    *plVar24 = *plVar24 + 1;
  }
  pcVar13 = DAT_23ed6a4f8;
  if (pcVar14 == (code *)0x0) {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar14 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong *)(pcVar13 + 0x10) = 0;
    *(longlong **)(pcVar13 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    local_148 = _PyRuntime_exref;
    *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
    lVar20 = *(longlong *)(local_148 + 0x1f8);
    *(undefined4 *)(pcVar13 + 0x24) = uVar23;
    lVar20 = *(longlong *)(*(longlong *)(lVar20 + 0x10) + 0x2e8);
    lVar9 = *(longlong *)(pcVar13 + -8);
    puVar1 = *(undefined8 **)(lVar20 + 8);
    *puVar1 = pcVar13 + -0x10;
    *(longlong *)(pcVar13 + -0x10) = lVar20;
    *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar1;
    *(code **)(lVar20 + 8) = pcVar13 + -0x10;
    if ((local_c8[0] != (code *)0x0) &&
       (*(longlong *)local_c8[0] = *(longlong *)local_c8[0] + -1, *(longlong *)local_c8[0] == 0)) {
      (**(code **)(*(longlong *)(local_c8[0] + 8) + 0x30))(local_c8[0]);
    }
  }
  else {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar22 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar22;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar13 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    local_148 = _PyRuntime_exref;
    *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
    lVar20 = *(longlong *)(local_148 + 0x1f8);
    *(undefined4 *)(pcVar13 + 0x24) = uVar23;
    lVar20 = *(longlong *)(*(longlong *)(lVar20 + 0x10) + 0x2e8);
    lVar9 = *(longlong *)(pcVar13 + -8);
    puVar1 = *(undefined8 **)(lVar20 + 8);
    *puVar1 = pcVar13 + -0x10;
    *(longlong *)(pcVar13 + -0x10) = lVar20;
    *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar1;
    *(code **)(lVar20 + 8) = pcVar13 + -0x10;
    *(code **)(pcVar13 + 0x10) = pcVar14;
    *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
    if ((local_c8[0] != (code *)0x0) &&
       (*(longlong *)local_c8[0] = *(longlong *)local_c8[0] + -1, *(longlong *)local_c8[0] == 0)) {
      (**(code **)(*(longlong *)(local_c8[0] + 8) + 0x30))();
    }
  }
  local_c8[0] = pcVar13;
  if (((code *)local_d8._0_8_ != _Py_NoneStruct_exref) && ((code *)local_d8._0_8_ != (code *)0x0)) {
    FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
  }
  plVar11 = *(longlong **)(local_d8._8_8_ + 0x28);
  if (local_c8[0] == _Py_NoneStruct_exref) {
    pcVar14 = (code *)0x0;
  }
  else {
    pcVar14 = local_c8[0];
    if (local_c8[0] != (code *)0x0) {
      *(longlong *)local_c8[0] = *(longlong *)local_c8[0] + 1;
    }
  }
  *(code **)(local_d8._8_8_ + 0x28) = pcVar14;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))();
  }
  plVar11 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = local_d8._8_8_;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))();
  }
  *(longlong *)local_d8._0_8_ = *(longlong *)local_d8._0_8_ + -1;
  if (*(longlong *)local_d8._0_8_ == 0) {
    (**(code **)(*(longlong *)(local_d8._0_8_ + 8) + 0x30))();
  }
  if ((local_c8[0] != (code *)0x0) &&
     (*(longlong *)local_c8[0] = *(longlong *)local_c8[0] + -1, *(longlong *)local_c8[0] == 0)) {
    (**(code **)(*(longlong *)(local_c8[0] + 8) + 0x30))();
  }
  pcVar22 = *(code **)(param_1 + 0x138);
  local_c8[0] = (code *)0x0;
  local_d8 = (undefined1  [16])0x0;
  pcVar14 = *(code **)PyExc_Exception_exref;
  pcVar13 = *(code **)(pcVar22 + 8);
  if ((*(uint *)(*(longlong *)(pcVar14 + 8) + 0xa8) & 0x4000000) == 0) {
    if (((int)*(uint *)(*(longlong *)(pcVar14 + 8) + 0xa8) < 0) &&
       (((byte)pcVar14[0xab] & 0x40) != 0)) {
      pcVar2 = *(code **)(pcVar13 + 8);
      if ((*(uint *)(pcVar2 + 0xa8) & 0x40000000) == 0) {
        if ((-1 < (int)*(uint *)(pcVar2 + 0xa8)) || (((byte)pcVar13[0xab] & 0x40) == 0))
        goto LAB_23e7eccd2;
      }
      else {
        pcVar13 = pcVar2;
        if (-1 < *(int *)(*(longlong *)(pcVar2 + 8) + 0xa8)) {
LAB_23e7eccd2:
          if (pcVar14 != pcVar13) goto LAB_23e7eb628;
          goto LAB_23e7eb785;
        }
      }
      lVar20 = *(longlong *)(pcVar13 + 0x158);
      if (lVar20 == 0) {
        do {
          if (pcVar14 == pcVar13) goto LAB_23e7eb785;
          pcVar13 = *(code **)(pcVar13 + 0x100);
        } while (pcVar13 != (code *)0x0);
        if (pcVar14 == PyBaseObject_Type_exref) goto LAB_23e7eb785;
      }
      else if (0 < *(longlong *)(lVar20 + 0x10)) {
        lVar9 = 0;
        do {
          if (pcVar14 == *(code **)(lVar20 + 0x18 + lVar9 * 8)) goto LAB_23e7eb785;
          lVar9 = lVar9 + 1;
        } while (*(longlong *)(lVar20 + 0x10) != lVar9);
      }
      goto LAB_23e7eb628;
    }
LAB_23e7eb718:
    plVar11 = *(longlong **)PyExc_TypeError_exref;
    uVar10 = PyUnicode_FromString
                       ("catching classes that do not inherit from BaseException is not allowed");
    plVar12 = *(longlong **)(param_1 + 0x60);
    plVar16 = *(longlong **)(param_1 + 0x68);
    plVar15 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar11;
    *plVar11 = *plVar11 + 1;
    *(undefined8 *)(param_1 + 0x68) = uVar10;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    if ((plVar15 == (longlong *)0x0) || (*plVar15 = *plVar15 + -1, *plVar15 != 0)) {
LAB_23e7eb77e:
      pcVar22 = *(code **)(param_1 + 0x138);
    }
    else {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
      pcVar22 = *(code **)(param_1 + 0x138);
    }
LAB_23e7eb785:
    *(longlong **)(param_1 + 0x138) = plVar24;
    if ((pcVar22 != (code *)0x0) &&
       (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
      (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
    }
    lVar9 = DAT_23ed6cce8;
    lVar20 = *(longlong *)(param_1 + 0x10);
    plVar11 = *(longlong **)(DAT_23ed6cce8 + 0x20);
    iVar8 = *(int *)(lVar20 + 0x1410);
    *plVar11 = *plVar11 + 1;
    if (iVar8 == 0) {
      plVar24 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
      plVar11 = *(longlong **)(lVar9 + 0x20);
    }
    else {
      iVar8 = iVar8 + -1;
      *(int *)(lVar20 + 0x1410) = iVar8;
      plVar24 = *(longlong **)(lVar20 + 0x1190 + (longlong)iVar8 * 8);
      *plVar24 = 1;
    }
    pcVar14 = DAT_23eeddba8;
    lVar20 = *(longlong *)(lVar9 + 0x28);
    plVar24[2] = 0;
    plVar24[4] = (longlong)plVar11;
    plVar24[5] = lVar20;
    lVar20 = *(longlong *)(pcVar14 + 0x20);
    plVar24[3] = 1;
    if (*(char *)(lVar20 + 10) != '\0') {
      iVar8 = *(int *)(lVar20 + 0xc);
      if (*(int *)(lVar20 + 0xc) == 0) {
        *(int *)(lVar20 + 0xc) = DAT_23ec15618;
        iVar8 = DAT_23ec15618;
        DAT_23ec15618 = DAT_23ec15618 + 1;
      }
      if (DAT_23ec155f0 != iVar8) {
        DAT_23ec155f0 = iVar8;
        DAT_23eedeaf0 = FUN_23e8cbd60(lVar20,DAT_23eeddde8,*(undefined8 *)(DAT_23eeddde8 + 0x18));
      }
      if (-1 < DAT_23eedeaf0) {
        lVar9 = lVar20 + 0x20 + (1L << (*(byte *)(lVar20 + 9) & 0x3f));
        lVar25 = *(longlong *)(lVar9 + 8 + DAT_23eedeaf0 * 0x10);
        if (lVar25 != 0) goto LAB_23e7eb864;
        DAT_23eedeaf0 = FUN_23e8cbd60(lVar20,DAT_23eeddde8,*(undefined8 *)(DAT_23eeddde8 + 0x18));
        if (-1 < DAT_23eedeaf0) {
          lVar25 = *(longlong *)(lVar9 + 8 + DAT_23eedeaf0 * 0x10);
          goto LAB_23e7ec908;
        }
      }
LAB_23e7ebcb9:
      plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeddde8);
      lVar20 = DAT_23eeddde8;
      if ((plVar11 != (longlong *)0x0) && (lVar25 = *plVar11, lVar25 != 0)) goto LAB_23e7eb864;
LAB_23e7ebcef:
      FUN_23e915740(param_1,local_b8,lVar20);
      if (local_a8 == (code *)0x0) goto LAB_23e7ec810;
      if (plVar3 != *(longlong **)(local_a8 + 0x18)) {
        plVar11 = (longlong *)0x0;
        local_138 = (longlong *)0x0;
        in_R11 = (longlong *)0x0;
        iVar8 = 0x89;
        local_150 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        goto LAB_23e7ebd40;
      }
LAB_23e7ec380:
      local_150 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      local_138 = (longlong *)0x0;
      in_R11 = (longlong *)0x0;
      local_158 = (longlong *)0x0;
      pcVar14 = local_a8;
      goto LAB_23e7ebdf9;
    }
    plVar11 = (longlong *)FUN_23a37a020(pcVar14,DAT_23eeddde8);
    if (plVar11 == (longlong *)0x0) goto LAB_23e7ebcb9;
    lVar25 = *plVar11;
LAB_23e7ec908:
    if (lVar25 == 0) goto LAB_23e7ebcb9;
LAB_23e7eb864:
    lVar20 = *(longlong *)(DAT_23eeddba8 + 0x20);
    if (*(char *)(lVar20 + 10) == '\0') {
      plVar11 = (longlong *)FUN_23a37a020(DAT_23eeddba8,DAT_23ed6cd80);
      if (plVar11 == (longlong *)0x0) goto LAB_23e7ec0f9;
      lVar20 = *plVar11;
LAB_23e7ec968:
      if (lVar20 == 0) goto LAB_23e7ec0f9;
    }
    else {
      iVar8 = *(int *)(lVar20 + 0xc);
      if (*(int *)(lVar20 + 0xc) == 0) {
        *(int *)(lVar20 + 0xc) = DAT_23ec15618;
        iVar8 = DAT_23ec15618;
        DAT_23ec15618 = DAT_23ec15618 + 1;
      }
      if (DAT_23ec155f4 != iVar8) {
        DAT_23ec155f4 = iVar8;
        DAT_23eedeaf8 = FUN_23e8cbd60(lVar20,DAT_23ed6cd80,*(undefined8 *)(DAT_23ed6cd80 + 0x18));
      }
      if (-1 < DAT_23eedeaf8) {
        lVar9 = lVar20 + 0x20 + (1L << (*(byte *)(lVar20 + 9) & 0x3f));
        if (*(longlong *)(lVar9 + 8 + DAT_23eedeaf8 * 0x10) != 0) goto LAB_23e7eb8d1;
        DAT_23eedeaf8 = FUN_23e8cbd60(lVar20,DAT_23ed6cd80,*(undefined8 *)(DAT_23ed6cd80 + 0x18));
        if (-1 < DAT_23eedeaf8) {
          lVar20 = *(longlong *)(lVar9 + 8 + DAT_23eedeaf8 * 0x10);
          goto LAB_23e7ec968;
        }
      }
LAB_23e7ec0f9:
      plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cd80);
      lVar20 = DAT_23ed6cd80;
      if ((plVar11 == (longlong *)0x0) || (*plVar11 == 0)) goto LAB_23e7ebcef;
    }
LAB_23e7eb8d1:
    *(undefined4 *)(plVar3 + 5) = 0x89;
    plVar11 = (longlong *)FUN_23e914090(param_1,lVar25);
    if (plVar11 != (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6cfb0);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))();
      }
      if (plVar12 == (longlong *)0x0) {
        local_b8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_a8 == (code *)0x0) goto LAB_23e7ec810;
        plVar11 = *(longlong **)(local_a8 + 0x18);
joined_r0x00023e7ec36b:
        if (plVar3 == plVar11) goto LAB_23e7ec380;
        local_138 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        in_R11 = (longlong *)0x0;
        iVar8 = 0x89;
        local_158 = (longlong *)0x0;
        goto LAB_23e7ebd40;
      }
      plVar11 = (longlong *)FUN_23e8bc2f0(plVar12,DAT_23ed6cfb0);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))();
      }
      if (plVar11 == (longlong *)0x0) goto LAB_23e7ec3a0;
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6cfb0);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))();
      }
      if (plVar12 == (longlong *)0x0) {
        local_b8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_a8 != (code *)0x0) {
          plVar11 = *(longlong **)(local_a8 + 0x18);
          goto joined_r0x00023e7ec36b;
        }
LAB_23e7ec810:
        plVar11 = (longlong *)0x0;
        local_138 = (longlong *)0x0;
        in_R11 = (longlong *)0x0;
        iVar8 = 0x89;
        local_150 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        goto LAB_23e7ec830;
      }
      plVar11 = (longlong *)FUN_23e8c6f80(plVar12,DAT_23eedddf0);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))();
      }
      if (plVar11 == (longlong *)0x0) {
        local_b8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_a8 != (code *)0x0) {
          if (*(longlong **)(local_a8 + 0x18) == plVar3) goto LAB_23e7ec380;
          local_150 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          in_R11 = (longlong *)0x0;
          iVar8 = 0x89;
          local_158 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          goto LAB_23e7ebd40;
        }
        goto LAB_23e7ec810;
      }
      in_R11 = (longlong *)FUN_23e8c6f80(plVar11,DAT_23eedddf8);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))();
      }
      uVar10 = DAT_23ed6cee0;
      if (in_R11 == (longlong *)0x0) {
        local_b8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_a8 == (code *)0x0) goto LAB_23e7ec810;
        plVar11 = *(longlong **)(local_a8 + 0x18);
        goto joined_r0x00023e7ec3db;
      }
      *(undefined4 *)(plVar3 + 5) = 0x8a;
      unaff_R12 = (longlong *)FUN_23e91bfe0(param_1,in_R11,uVar10);
      if (unaff_R12 == (longlong *)0x0) {
        local_b8 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_a8 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (local_a8 == (code *)0x0) goto LAB_23e7edc1d;
        if (*(longlong **)(local_a8 + 0x18) != plVar3) {
          local_150 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          iVar8 = 0x8a;
          local_158 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          goto LAB_23e7ebd40;
        }
LAB_23e7edbf0:
        local_150 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        local_138 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        pcVar14 = local_a8;
        goto LAB_23e7ebdf9;
      }
      iVar8 = FUN_23a35f020();
      plVar11 = (longlong *)(*unaff_R12 + -1);
      local_158 = in_R11;
      if (iVar8 == -1) goto LAB_23e7ed9f8;
      *unaff_R12 = (longlong)plVar11;
      if (plVar11 == (longlong *)0x0) {
        (**(code **)(unaff_R12[1] + 0x30))(unaff_R12);
      }
      if (iVar8 == 0) {
        local_150 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        local_138 = (longlong *)0x0;
LAB_23e7eba68:
        *plVar24 = *plVar24 + 1;
        plVar12 = plVar24;
LAB_23e7eba6f:
        lVar20 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar3 = *(longlong **)(lVar20 + 0x28);
        plVar16 = (longlong *)plVar3[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar20 + 0x30);
        *(undefined4 *)(plVar3 + 8) = 0xffffffff;
        if (plVar16 != (longlong *)0x0) {
          plVar3[2] = 0;
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))();
          }
        }
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))(plVar3);
        }
        plVar3[0xf] = 0;
        if ((local_160 != (longlong *)0x0) &&
           (lVar20 = *local_160, *local_160 = lVar20 + -1, lVar20 + -1 == 0)) {
          (**(code **)(local_160[1] + 0x30))(local_160);
        }
        if ((plVar24 != (longlong *)0x0) && (*plVar24 = *plVar24 + -1, *plVar24 == 0)) {
          (**(code **)(plVar24[1] + 0x30))(plVar24);
        }
        if ((in_R11 != (longlong *)0x0) && (*in_R11 = *in_R11 + -1, *in_R11 == 0)) {
          (**(code **)(in_R11[1] + 0x30))(in_R11);
        }
        if ((local_138 != (longlong *)0x0) &&
           (lVar20 = *local_138, *local_138 = lVar20 + -1, lVar20 + -1 == 0)) {
          (**(code **)(local_138[1] + 0x30))(local_138);
        }
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if ((local_158 != (longlong *)0x0) &&
           (lVar20 = *local_158, *local_158 = lVar20 + -1, lVar20 + -1 == 0)) {
          (**(code **)(local_158[1] + 0x30))(local_158);
        }
        if (local_150 != (longlong *)0x0) {
          lVar20 = *local_150;
          *local_150 = lVar20 + -1;
          if (lVar20 + -1 == 0) {
            (**(code **)(local_150[1] + 0x30))(local_150);
            return plVar12;
          }
          return plVar12;
        }
        return plVar12;
      }
      plVar12 = (longlong *)FUN_23e91c870(param_1,in_R11,DAT_23ed6ce80,DAT_23eedde00);
      if (plVar12 == (longlong *)0x0) {
        local_b8 = *(undefined1 (*) [16])(param_1 + 0x60);
        pcVar14 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023e7ecf62:
        local_a8 = pcVar14;
        if (pcVar14 != (code *)0x0) {
          plVar11 = *(longlong **)(pcVar14 + 0x18);
joined_r0x00023e7edbe6:
          local_a8 = pcVar14;
          if (plVar11 != plVar3) {
            local_150 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            iVar8 = 0x8b;
            local_158 = (longlong *)0x0;
            goto LAB_23e7ebd40;
          }
          goto LAB_23e7edbf0;
        }
LAB_23e7ede4c:
        local_150 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        local_138 = (longlong *)0x0;
        iVar8 = 0x8b;
        local_158 = (longlong *)0x0;
        goto LAB_23e7ec830;
      }
      plVar11 = (longlong *)FUN_23e8d9880(plVar12,DAT_23ed6cd90);
      if (plVar11 == (longlong *)0x0) {
        plVar16 = *(longlong **)*(undefined1 (*) [16])(param_1 + 0x60);
        pcVar13 = *(code **)(param_1 + 0x68);
        local_b8 = *(undefined1 (*) [16])(param_1 + 0x60);
        pcVar14 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar20 = *plVar12;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar12 = lVar20 + -1;
        if (lVar20 + -1 == 0) {
LAB_23e7edbb0:
          local_a8 = (code *)0x0;
          local_b8 = (undefined1  [16])0x0;
          (**(code **)(plVar12[1] + 0x30))();
          local_b8._8_8_ = pcVar13;
          local_b8._0_8_ = plVar16;
          local_a8 = pcVar14;
          if (pcVar14 != (code *)0x0) {
            plVar11 = *(longlong **)(pcVar14 + 0x18);
            goto joined_r0x00023e7edbe6;
          }
        }
        else {
          local_a8 = pcVar14;
          if (pcVar14 != (code *)0x0) {
            if (plVar3 == *(longlong **)(pcVar14 + 0x18)) goto LAB_23e7edbf0;
            local_150 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            iVar8 = 0x8b;
            local_158 = (longlong *)0x0;
            local_138 = (longlong *)0x0;
            goto LAB_23e7ebd40;
          }
        }
        goto LAB_23e7ede4c;
      }
      *(undefined4 *)(plVar3 + 5) = 0x8b;
      local_138 = (longlong *)FUN_23e91a870(param_1,plVar11);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))();
      }
      if (local_138 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar13 = *(code **)(param_1 + 0x68);
        pcVar14 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar20 = *plVar12;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar12 = lVar20 + -1;
        if (lVar20 + -1 == 0) goto LAB_23e7edbb0;
LAB_23e7ede33:
        local_b8._8_8_ = pcVar13;
        local_b8._0_8_ = plVar16;
        goto joined_r0x00023e7ecf62;
      }
      plVar15 = (longlong *)FUN_23e8d9880(plVar12,DAT_23ed6cd98);
      if (plVar15 == (longlong *)0x0) {
        plVar16 = *(longlong **)(param_1 + 0x60);
        pcVar13 = *(code **)(param_1 + 0x68);
        local_a8 = (code *)0x0;
        pcVar14 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        lVar20 = *plVar12;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_b8 = (undefined1  [16])0x0;
        *plVar12 = lVar20 + -1;
        if (lVar20 + -1 == 0) {
          local_150 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          iVar8 = 0x8b;
          local_158 = (longlong *)0x0;
          plVar21 = (longlong *)0x0;
          goto LAB_23e7ee12a;
        }
        lVar20 = *local_138;
        *local_138 = lVar20 + -1;
        if (lVar20 + -1 != 0) goto LAB_23e7ede33;
        plVar12 = local_138 + 1;
        local_138 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        iVar8 = 0x8b;
        (**(code **)(*plVar12 + 0x30))();
        local_158 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
      }
      else {
        *local_138 = *local_138 + 1;
        plVar16 = (longlong *)FUN_23ebf7180(local_138);
        if (plVar16 == (longlong *)0x0) {
          uVar10 = *(undefined8 *)(param_1 + 0x60);
          pcVar14 = *(code **)(param_1 + 0x70);
          plVar11 = (longlong *)0x0;
          uVar23 = 0x8c;
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_150 = (longlong *)0x0;
          local_158 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar26 = *(undefined8 *)(param_1 + 0x68);
        }
        else {
          local_150 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          local_158 = (longlong *)0x0;
          plVar21 = (longlong *)0x0;
          do {
            pcVar14 = *(code **)(plVar16[1] + 0xe0);
            if (pcVar14 == (code *)0x0) {
              PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                           *(undefined8 *)(plVar16[1] + 0x18));
LAB_23e7edabe:
              cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
              if (cVar7 == '\0') {
                pcVar14 = *(code **)(param_1 + 0x70);
                uVar10 = *(undefined8 *)(param_1 + 0x60);
                uVar26 = *(undefined8 *)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_a8 = (code *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                local_b8 = (undefined1  [16])0x0;
                if (plVar21 != (longlong *)0x0) {
                  uVar23 = 0x8c;
                  goto LAB_23e7ed0cd;
                }
                uVar23 = 0x8c;
                goto LAB_23e7ed0fe;
              }
              if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
                FUN_23a334bc0(plVar21);
              }
              lVar20 = *plVar16;
              *plVar16 = lVar20 + -1;
              if (lVar20 + -1 == 0) {
                FUN_23a334bc0(plVar16);
              }
              uVar10 = DAT_23eedde28;
              *(undefined4 *)(plVar3 + 5) = 0x8b;
              plVar16 = (longlong *)FUN_23e957a30(param_1,plVar15,uVar10);
              if (plVar16 != (longlong *)0x0) {
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  FUN_23a334bc0();
                }
                goto LAB_23e7ed4b7;
              }
              plVar16 = *(longlong **)(param_1 + 0x60);
              pcVar13 = *(code **)(param_1 + 0x68);
              pcVar14 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              iVar8 = 0x8b;
              *(undefined8 *)(param_1 + 0x70) = 0;
              goto LAB_23e7ee077;
            }
            plVar17 = (longlong *)(*pcVar14)(plVar16);
            if (plVar17 == (longlong *)0x0) goto LAB_23e7edabe;
            if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
              (**(code **)(plVar21[1] + 0x30))(plVar21);
            }
            *plVar17 = *plVar17 + 1;
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            plVar18 = (longlong *)FUN_23e8bc2f0(plVar17,DAT_23eeddbf8);
            plVar21 = plVar17;
            if (plVar18 == (longlong *)0x0) {
LAB_23e7edd9f:
              uVar10 = *(undefined8 *)(param_1 + 0x60);
              uVar26 = *(undefined8 *)(param_1 + 0x68);
              pcVar14 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar23 = 0x8d;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar11 = plVar17;
              goto LAB_23e7ed0cd;
            }
            *(undefined4 *)(plVar3 + 5) = 0x8d;
            plVar11 = (longlong *)FUN_23e91a870(param_1,plVar18);
            *plVar18 = *plVar18 + -1;
            if (*plVar18 == 0) {
              (**(code **)(plVar18[1] + 0x30))(plVar18);
            }
            lVar20 = *plVar17;
            if (plVar11 == (longlong *)0x0) goto LAB_23e7edd9f;
            *plVar17 = lVar20 + -1;
            if (lVar20 + -1 == 0) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
            }
            iVar8 = PySequence_Contains(plVar11,DAT_23eedde08);
            if (iVar8 == -1) {
              pcVar14 = *(code **)(param_1 + 0x70);
              uVar10 = *(undefined8 *)(param_1 + 0x60);
              uVar26 = *(undefined8 *)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar23 = 0x8e;
              goto LAB_23e7ed0cd;
            }
            if (iVar8 == 1) {
              plVar17 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6d020);
              uVar10 = DAT_23eedde10;
              if (plVar17 == (longlong *)0x0) {
LAB_23e7ee4ee:
                uVar10 = *(undefined8 *)(param_1 + 0x60);
                uVar26 = *(undefined8 *)(param_1 + 0x68);
                pcVar14 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                *(undefined4 *)(plVar3 + 5) = 0x8f;
                plVar18 = (longlong *)FUN_23e9557e0(param_1,plVar17,uVar10);
                *plVar17 = *plVar17 + -1;
                if (*plVar17 == 0) {
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                if (plVar18 == (longlong *)0x0) goto LAB_23e7ee4ee;
                plVar17 = (longlong *)FUN_23a388310(plVar18);
                *plVar18 = *plVar18 + -1;
                if (*plVar18 == 0) {
                  (**(code **)(plVar18[1] + 0x30))(plVar18);
                }
                if (plVar17 == (longlong *)0x0) goto LAB_23e7ee4ee;
                plVar18 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                if ((plVar18 == (longlong *)0x0) &&
                   (plVar18 = (longlong *)FUN_23a3c1b70(param_1,local_b8,0,2), pcVar14 = local_a8,
                   plVar18 == (longlong *)0x0)) {
                  uVar10 = local_b8._0_8_;
                  uVar26 = local_b8._8_8_;
                  local_b8 = (undefined1  [16])0x0;
                  local_a8 = (code *)0x0;
                  *plVar17 = *plVar17 + -1;
                  if (*plVar17 == 0) {
                    FUN_23a334bc0(plVar17);
                  }
                }
                else {
                  plVar19 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                  if ((plVar19 == (longlong *)0x0) &&
                     (plVar19 = (longlong *)FUN_23a3c1b70(param_1,local_b8,1,2),
                     plVar19 == (longlong *)0x0)) {
                    lVar20 = *plVar17;
                  }
                  else {
                    cVar7 = FUN_23a3884a0(param_1,local_b8,plVar17,2);
                    lVar20 = *plVar17;
                    if (cVar7 != '\0') {
                      *plVar17 = lVar20 + -1;
                      if (lVar20 + -1 == 0) {
                        (**(code **)(plVar17[1] + 0x30))(plVar17);
                      }
                      lVar20 = *plVar18;
                      *plVar18 = lVar20 + 1;
                      if (local_158 != (longlong *)0x0) {
                        lVar20 = *local_158;
                        *local_158 = lVar20 + -1;
                        if (lVar20 + -1 == 0) {
                          (**(code **)(local_158[1] + 0x30))(local_158);
                        }
                        lVar20 = *plVar18 + -1;
                      }
                      *plVar18 = lVar20;
                      if (lVar20 == 0) {
                        (**(code **)(plVar18[1] + 0x30))(plVar18);
                      }
                      lVar20 = *plVar19;
                      *plVar19 = lVar20 + 1;
                      if (local_150 != (longlong *)0x0) {
                        lVar20 = *local_150;
                        *local_150 = lVar20 + -1;
                        if (lVar20 + -1 == 0) {
                          (**(code **)(local_150[1] + 0x30))(local_150);
                        }
                        lVar20 = *plVar19 + -1;
                      }
                      *plVar19 = lVar20;
                      if (lVar20 == 0) {
                        (**(code **)(plVar19[1] + 0x30))(plVar19);
                      }
                      plVar17 = (longlong *)FUN_23e8bc2f0(plVar18,DAT_23eeddd78);
                      uVar10 = DAT_23eedde18;
                      local_150 = plVar19;
                      local_158 = plVar18;
                      if (plVar17 != (longlong *)0x0) {
                        *(undefined4 *)(plVar3 + 5) = 0x90;
                        plVar18 = (longlong *)FUN_23e9557e0(param_1,plVar17,uVar10);
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          (**(code **)(plVar17[1] + 0x30))(plVar17);
                        }
                        if (plVar18 != (longlong *)0x0) {
                          plVar17 = (longlong *)FUN_23e8bc2f0(plVar19,DAT_23eeddbf8);
                          if (plVar17 != (longlong *)0x0) {
                            *(undefined4 *)(plVar3 + 5) = 0x90;
                            plVar19 = (longlong *)FUN_23e91a870(param_1,plVar17);
                            *plVar17 = *plVar17 + -1;
                            if (*plVar17 == 0) {
                              (**(code **)(plVar17[1] + 0x30))(plVar17);
                            }
                            if (plVar19 != (longlong *)0x0) {
                              iVar8 = PyDict_SetItem(plVar24,plVar19,plVar18);
                              *plVar18 = *plVar18 + -1;
                              if (*plVar18 == 0) {
                                (**(code **)(plVar18[1] + 0x30))(plVar18);
                              }
                              *plVar19 = *plVar19 + -1;
                              if (*plVar19 == 0) {
                                (**(code **)(plVar19[1] + 0x30))(plVar19);
                              }
                              if (iVar8 == 0) goto LAB_23e7ecbd9;
                              goto LAB_23e7ee58d;
                            }
                          }
                          local_b8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                          local_b8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                          local_a8 = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar18 = *plVar18 + -1;
                          if (*plVar18 == 0) {
                            FUN_23a334bc0(plVar18);
                            uVar23 = 0x90;
                            pcVar14 = local_a8;
                            uVar10 = local_b8._0_8_;
                            uVar26 = local_b8._8_8_;
                          }
                          else {
                            uVar23 = 0x90;
                            pcVar14 = local_a8;
                            uVar10 = local_b8._0_8_;
                            uVar26 = local_b8._8_8_;
                          }
                          goto LAB_23e7ed0cd;
                        }
                      }
LAB_23e7ee58d:
                      pcVar14 = *(code **)(param_1 + 0x70);
                      uVar10 = *(undefined8 *)(param_1 + 0x60);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar23 = 0x90;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar26 = *(undefined8 *)(param_1 + 0x68);
                      goto LAB_23e7ed0cd;
                    }
                  }
                  pcVar14 = local_a8;
                  uVar10 = local_b8._0_8_;
                  uVar26 = local_b8._8_8_;
                  local_b8 = (undefined1  [16])0x0;
                  local_a8 = (code *)0x0;
                  *plVar17 = lVar20 + -1;
                  if (lVar20 + -1 == 0) {
                    FUN_23a334bc0(plVar17);
                  }
                  local_a8 = (code *)0x0;
                  local_b8 = (undefined1  [16])0x0;
                  *plVar18 = *plVar18 + -1;
                  if (*plVar18 == 0) {
                    (**(code **)(plVar18[1] + 0x30))(plVar18);
                  }
                  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                    (**(code **)(plVar19[1] + 0x30))(plVar19);
                  }
                }
              }
              uVar23 = 0x8f;
              goto LAB_23e7ed0cd;
            }
LAB_23e7ecbd9:
            lVar20 = *(longlong *)(param_1 + 0x10);
            if ((((*(int *)(*(longlong *)(lVar20 + 0x28) + 0x160) != 0) ||
                 (*(int *)(lVar20 + 0x78) != 0)) && (iVar8 = Py_MakePendingCalls(), iVar8 < 0)) &&
               (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e7ed09b;
            if (*(int *)(lVar20 + 0x68) == 0) {
              plVar17 = *(longlong **)(param_1 + 0x90);
            }
            else {
              PyEval_SaveThread();
              PyEval_AcquireThread(param_1);
              plVar17 = *(longlong **)(param_1 + 0x90);
            }
          } while (plVar17 == (longlong *)0x0);
          plVar18 = *(longlong **)(param_1 + 0x60);
          plVar19 = *(longlong **)(param_1 + 0x68);
          *(undefined8 *)(param_1 + 0x90) = 0;
          plVar4 = *(longlong **)(param_1 + 0x70);
          *(longlong **)(param_1 + 0x60) = plVar17;
          *plVar17 = *plVar17 + 1;
          *(undefined8 *)(param_1 + 0x68) = 0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
            (**(code **)(plVar18[1] + 0x30))();
          }
          if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
          }
          if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
            (**(code **)(plVar4[1] + 0x30))(plVar4);
          }
LAB_23e7ed09b:
          pcVar14 = *(code **)(param_1 + 0x70);
          uVar10 = *(undefined8 *)(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar23 = 0x8c;
          uVar26 = *(undefined8 *)(param_1 + 0x68);
LAB_23e7ed0cd:
          local_a8 = (code *)0x0;
          local_b8 = (undefined1  [16])0x0;
          *plVar21 = *plVar21 + -1;
          if (*plVar21 == 0) {
            (**(code **)(plVar21[1] + 0x30))(plVar21);
          }
LAB_23e7ed0fe:
          lVar20 = *plVar16;
          *plVar16 = lVar20 + -1;
          if (lVar20 + -1 == 0) {
            (**(code **)(plVar16[1] + 0x30))();
          }
        }
        local_b8._8_8_ = uVar26;
        local_b8._0_8_ = uVar10;
        local_a8 = pcVar14;
        pcVar14 = local_a8;
        local_f8._8_8_ = local_b8._8_8_;
        local_f8._0_8_ = local_b8._0_8_;
        local_a8 = (code *)0x0;
        local_b8 = (undefined1  [16])0x0;
        local_e8[0] = pcVar14;
        plVar21 = *(longlong **)(param_1 + 0x138);
        if (plVar21 != (longlong *)0x0) {
          *plVar21 = *plVar21 + 1;
        }
        pcVar13 = DAT_23ed6a4f8;
        if (pcVar14 == (code *)0x0) {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar14 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar14;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong *)(pcVar13 + 0x10) = 0;
          *(longlong **)(pcVar13 + 0x18) = plVar3;
          *plVar3 = *plVar3 + 1;
          *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
          lVar20 = *(longlong *)(local_148 + 0x1f8);
          *(undefined4 *)(pcVar13 + 0x24) = uVar23;
          lVar20 = *(longlong *)(*(longlong *)(lVar20 + 0x10) + 0x2e8);
          lVar9 = *(longlong *)(pcVar13 + -8);
          puVar1 = *(undefined8 **)(lVar20 + 8);
          *puVar1 = pcVar13 + -0x10;
          *(longlong *)(pcVar13 + -0x10) = lVar20;
          *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar1;
          *(code **)(lVar20 + 8) = pcVar13 + -0x10;
          if ((local_e8[0] != (code *)0x0) &&
             (*(longlong *)local_e8[0] = *(longlong *)local_e8[0] + -1,
             *(longlong *)local_e8[0] == 0)) {
            (**(code **)(*(longlong *)(local_e8[0] + 8) + 0x30))(local_e8[0]);
          }
        }
        else {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar13 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar22 = *(code **)DAT_23ed6a4f8;
            *(longlong *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar22;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong **)(pcVar13 + 0x18) = plVar3;
          *plVar3 = *plVar3 + 1;
          *(undefined4 *)(pcVar13 + 0x20) = 0xffffffff;
          lVar20 = *(longlong *)(local_148 + 0x1f8);
          *(undefined4 *)(pcVar13 + 0x24) = uVar23;
          lVar20 = *(longlong *)(*(longlong *)(lVar20 + 0x10) + 0x2e8);
          lVar9 = *(longlong *)(pcVar13 + -8);
          puVar1 = *(undefined8 **)(lVar20 + 8);
          *puVar1 = pcVar13 + -0x10;
          *(longlong *)(pcVar13 + -0x10) = lVar20;
          *(ulonglong *)(pcVar13 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar1;
          *(code **)(lVar20 + 8) = pcVar13 + -0x10;
          *(code **)(pcVar13 + 0x10) = pcVar14;
          *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
          if ((local_e8[0] != (code *)0x0) &&
             (*(longlong *)local_e8[0] = *(longlong *)local_e8[0] + -1,
             *(longlong *)local_e8[0] == 0)) {
            (**(code **)(*(longlong *)(local_e8[0] + 8) + 0x30))();
          }
        }
        local_e8[0] = pcVar13;
        if (((code *)local_f8._0_8_ != _Py_NoneStruct_exref) &&
           ((code *)local_f8._0_8_ != (code *)0x0)) {
          FUN_23e91b1b0(param_1,local_f8,local_f8 + 8,local_e8);
        }
        plVar16 = *(longlong **)(local_f8._8_8_ + 0x28);
        if (local_e8[0] == _Py_NoneStruct_exref) {
          pcVar14 = (code *)0x0;
        }
        else {
          pcVar14 = local_e8[0];
          if (local_e8[0] != (code *)0x0) {
            *(longlong *)local_e8[0] = *(longlong *)local_e8[0] + 1;
          }
        }
        *(code **)(local_f8._8_8_ + 0x28) = pcVar14;
        if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
          (**(code **)(plVar16[1] + 0x30))();
        }
        plVar16 = *(longlong **)(param_1 + 0x138);
        *(undefined8 *)(param_1 + 0x138) = local_f8._8_8_;
        if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
          (**(code **)(plVar16[1] + 0x30))();
        }
        *(longlong *)local_f8._0_8_ = *(longlong *)local_f8._0_8_ + -1;
        if (*(longlong *)local_f8._0_8_ == 0) {
          (**(code **)(*(longlong *)(local_f8._0_8_ + 8) + 0x30))();
        }
        if ((local_e8[0] != (code *)0x0) &&
           (*(longlong *)local_e8[0] = *(longlong *)local_e8[0] + -1, *(longlong *)local_e8[0] == 0)
           ) {
          (**(code **)(*(longlong *)(local_e8[0] + 8) + 0x30))();
        }
        local_e8[0] = (code *)0x0;
        local_f8 = (undefined1  [16])0x0;
        iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                              *(undefined8 *)PyExc_BaseException_exref);
        if (iVar8 == 0) {
          pcVar22 = *(code **)(param_1 + 0x138);
          local_b8._8_8_ = pcVar22;
          if ((pcVar22 == _Py_NoneStruct_exref) || (pcVar22 == (code *)0x0)) {
            iVar8 = 0x8b;
            plVar16 = *(longlong **)PyExc_RuntimeError_exref;
            pcVar13 = (code *)PyUnicode_FromString("No active exception to reraise");
            *plVar16 = *plVar16 + 1;
LAB_23e7ee625:
            pcVar22 = *(code **)(param_1 + 0x138);
            pcVar14 = (code *)0x0;
            bVar5 = true;
            goto LAB_23e7ee203;
          }
          plVar16 = *(longlong **)(pcVar22 + 8);
          pcVar14 = *(code **)(pcVar22 + 0x28);
          *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
          *plVar16 = *plVar16 + 1;
          iVar8 = 0;
          pcVar13 = pcVar22;
          if (pcVar14 == (code *)0x0) goto LAB_23e7ee625;
          *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
          if (*(longlong **)(pcVar14 + 0x18) == plVar3) {
            *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar14 + 0x24);
          }
          bVar5 = true;
LAB_23e7edfaf:
          *(longlong **)(param_1 + 0x138) = plVar21;
          iVar8 = 0;
          pcVar13 = pcVar22;
LAB_23e7edfd1:
          local_a8 = (code *)0x0;
          local_b8 = (undefined1  [16])0x0;
          *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
          if (*(longlong *)pcVar22 == 0) {
            (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))();
          }
        }
        else {
          pcStack_90 = *(code **)(param_1 + 0x138);
          local_98 = *(longlong **)(pcStack_90 + 8);
          local_88 = *(code **)(pcStack_90 + 0x28);
          *(undefined4 *)(plVar3 + 5) = 0x8b;
          if (local_88 == (code *)0x0) {
            local_88 = _Py_NoneStruct_exref;
          }
          plVar16 = (longlong *)FUN_23e956150(param_1,plVar15,&local_98);
          if (plVar16 == (longlong *)0x0) {
            pcVar14 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            iVar8 = 0x8b;
            bVar5 = false;
            pcVar22 = *(code **)(param_1 + 0x138);
            plVar16 = *(longlong **)(param_1 + 0x60);
            pcVar13 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            iVar8 = FUN_23a35f020(plVar16);
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            if (iVar8 == -1) {
              plVar16 = *(longlong **)(param_1 + 0x60);
              pcVar13 = *(code **)(param_1 + 0x68);
              bVar5 = false;
              pcVar14 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              pcVar22 = *(code **)(param_1 + 0x138);
              iVar8 = 0x8b;
              *(undefined8 *)(param_1 + 0x70) = 0;
            }
            else {
              if (iVar8 != 0) {
                plVar3 = *(longlong **)(param_1 + 0x138);
                *(longlong **)(param_1 + 0x138) = plVar21;
                if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
                  (**(code **)(plVar3[1] + 0x30))();
                }
LAB_23e7ed4b7:
                lVar20 = *plVar12;
                *plVar12 = lVar20 + -1;
                if (lVar20 + -1 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                lVar20 = *local_138;
                *local_138 = lVar20 + -1;
                if (lVar20 + -1 == 0) {
                  (**(code **)(local_138[1] + 0x30))(local_138);
                }
                lVar20 = *plVar15;
                *plVar15 = lVar20 + -1;
                if (lVar20 + -1 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                goto LAB_23e7eba68;
              }
              pcVar22 = *(code **)(param_1 + 0x138);
              local_b8._8_8_ = pcVar22;
              bVar5 = false;
              if ((pcVar22 != _Py_NoneStruct_exref) && (pcVar22 != (code *)0x0)) {
                plVar16 = *(longlong **)(pcVar22 + 8);
                pcVar14 = *(code **)(pcVar22 + 0x28);
                *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                *plVar16 = *plVar16 + 1;
                if (pcVar14 != (code *)0x0) {
                  *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
                  if (*(longlong **)(pcVar14 + 0x18) == plVar3) {
                    *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar14 + 0x24);
                  }
                  goto LAB_23e7edfaf;
                }
                *(longlong **)(param_1 + 0x138) = plVar21;
                iVar8 = 0;
                pcVar13 = pcVar22;
                goto LAB_23e7edfd1;
              }
              iVar8 = 0x8b;
              plVar16 = *(longlong **)PyExc_RuntimeError_exref;
              pcVar13 = (code *)PyUnicode_FromString("No active exception to reraise");
              pcVar22 = *(code **)(param_1 + 0x138);
              pcVar14 = (code *)0x0;
              *plVar16 = *plVar16 + 1;
            }
          }
LAB_23e7ee203:
          *(longlong **)(param_1 + 0x138) = plVar21;
          if (pcVar22 != (code *)0x0) goto LAB_23e7edfd1;
        }
        local_a8 = (code *)0x0;
        local_b8 = (undefined1  [16])0x0;
        local_98 = plVar16;
        pcStack_90 = pcVar13;
        local_88 = pcVar14;
        if (bVar5) {
          *(undefined4 *)(plVar3 + 5) = 0x8b;
          plVar21 = (longlong *)FUN_23e957a30(param_1,plVar15);
          if (plVar21 == (longlong *)0x0) {
            local_a8 = *(code **)(param_1 + 0x70);
            local_b8._0_8_ = *(longlong *)(param_1 + 0x60);
            local_b8._8_8_ = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            iVar8 = 0x8b;
            FUN_23a35d6b0();
            pcVar14 = local_a8;
            plVar16 = (longlong *)local_b8._0_8_;
            pcVar13 = (code *)local_b8._8_8_;
          }
          else {
            *plVar21 = *plVar21 + -1;
            pcVar14 = local_88;
            plVar16 = local_98;
            pcVar13 = pcStack_90;
            if (*plVar21 == 0) {
              (**(code **)(plVar21[1] + 0x30))();
              pcVar14 = local_88;
              plVar16 = local_98;
              pcVar13 = pcStack_90;
            }
          }
        }
LAB_23e7ee077:
        local_a8 = (code *)0x0;
        local_b8 = (undefined1  [16])0x0;
        lVar20 = *plVar12;
        *plVar12 = lVar20 + -1;
        plVar21 = local_138;
        if (lVar20 + -1 == 0) {
LAB_23e7ee12a:
          local_a8 = (code *)0x0;
          local_b8 = (undefined1  [16])0x0;
          (**(code **)(plVar12[1] + 0x30))();
          lVar20 = *local_138;
          *local_138 = lVar20 + -1;
          if (lVar20 + -1 == 0) goto LAB_23e7ee0c4;
LAB_23e7ee0dd:
          local_138 = plVar21;
          if (plVar15 == (longlong *)0x0) goto LAB_23e7eb6db;
        }
        else {
          lVar20 = *local_138;
          *local_138 = lVar20 + -1;
          if (lVar20 + -1 == 0) {
LAB_23e7ee0c4:
            (**(code **)(local_138[1] + 0x30))();
            goto LAB_23e7ee0dd;
          }
        }
        lVar20 = *plVar15;
        *plVar15 = lVar20 + -1;
        if (lVar20 + -1 == 0) {
          (**(code **)(plVar15[1] + 0x30))();
        }
      }
      goto LAB_23e7eb6db;
    }
LAB_23e7ec3a0:
    in_R11 = (longlong *)0x0;
    local_b8 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_a8 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_a8 == (code *)0x0) goto LAB_23e7ec810;
    plVar11 = *(longlong **)(local_a8 + 0x18);
joined_r0x00023e7ec3db:
    if (plVar11 == plVar3) goto LAB_23e7ec380;
    local_150 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    local_138 = (longlong *)0x0;
    iVar8 = 0x89;
    local_158 = (longlong *)0x0;
LAB_23e7ebd40:
    pcVar13 = local_a8;
    pcVar14 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar22 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar22;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar14 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
    lVar20 = *(longlong *)(local_148 + 0x1f8);
    *(int *)(pcVar14 + 0x24) = iVar8;
    lVar20 = *(longlong *)(*(longlong *)(lVar20 + 0x10) + 0x2e8);
    lVar9 = *(longlong *)(pcVar14 + -8);
    puVar1 = *(undefined8 **)(lVar20 + 8);
    *puVar1 = pcVar14 + -0x10;
    *(longlong *)(pcVar14 + -0x10) = lVar20;
    *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar1;
    *(code **)(lVar20 + 8) = pcVar14 + -0x10;
    *(code **)(pcVar14 + 0x10) = pcVar13;
    *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
    if ((local_a8 != (code *)0x0) &&
       (*(longlong *)local_a8 = *(longlong *)local_a8 + -1, *(longlong *)local_a8 == 0)) {
      (**(code **)(*(longlong *)(local_a8 + 8) + 0x30))();
    }
  }
  else {
    lVar20 = *(longlong *)(pcVar14 + 0x10);
    if (0 < lVar20) {
      lVar9 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar14 + lVar9 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar14 + lVar9 * 8 + 0x18) + 0xab) & 0x40) == 0))
        goto LAB_23e7eb718;
        lVar9 = lVar9 + 1;
      } while (lVar20 != lVar9);
      lVar9 = 0;
      do {
        iVar8 = FUN_23a35ebd0(param_1,pcVar13,*(undefined8 *)(pcVar14 + lVar9 * 8 + 0x18));
        if (iVar8 != 0) goto LAB_23e7eb77e;
        lVar9 = lVar9 + 1;
      } while (lVar20 != lVar9);
      pcVar22 = *(code **)(param_1 + 0x138);
    }
LAB_23e7eb628:
    local_b8._8_8_ = pcVar22;
    if ((pcVar22 == _Py_NoneStruct_exref) || (pcVar22 == (code *)0x0)) {
      plVar16 = *(longlong **)PyExc_RuntimeError_exref;
      pcVar13 = (code *)PyUnicode_FromString();
      pcVar22 = *(code **)(param_1 + 0x138);
      *plVar16 = *plVar16 + 1;
      *(longlong **)(param_1 + 0x138) = plVar24;
      local_a8 = (code *)0x0;
      if (pcVar22 == (code *)0x0) {
        local_b8._8_8_ = pcVar13;
        local_b8._0_8_ = plVar16;
        plVar11 = (longlong *)0x0;
        local_138 = (longlong *)0x0;
        in_R11 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        iVar8 = 0x81;
        local_158 = (longlong *)0x0;
        plVar24 = (longlong *)0x0;
      }
      else {
        *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
        if (*(longlong *)pcVar22 == 0) {
          iVar8 = 0x81;
          pcVar14 = (code *)0x0;
LAB_23e7eb6b5:
          local_a8 = (code *)0x0;
          local_b8 = (undefined1  [16])0x0;
          plVar11 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          plVar24 = (longlong *)0x0;
          (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))();
          in_R11 = (longlong *)0x0;
          local_150 = (longlong *)0x0;
          local_158 = (longlong *)0x0;
LAB_23e7eb6db:
          local_b8._8_8_ = pcVar13;
          local_b8._0_8_ = plVar16;
          if (pcVar14 != (code *)0x0) goto LAB_23e7eb6f4;
          local_a8 = (code *)0x0;
          if (iVar8 == 0) goto LAB_23e7eccb0;
        }
        else {
          local_150 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          local_138 = (longlong *)0x0;
          plVar24 = (longlong *)0x0;
          local_a8 = (code *)0x0;
          iVar8 = 0x81;
          in_R11 = (longlong *)0x0;
          local_158 = (longlong *)0x0;
          local_b8._8_8_ = pcVar13;
          local_b8._0_8_ = plVar16;
        }
      }
    }
    else {
      plVar16 = *(longlong **)(pcVar22 + 8);
      pcVar14 = *(code **)(pcVar22 + 0x28);
      *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
      *plVar16 = *plVar16 + 1;
      if (pcVar14 != (code *)0x0) {
        *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
        if (*(longlong **)(pcVar14 + 0x18) == plVar3) {
          *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar14 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar24;
        *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
        if (*(longlong *)pcVar22 == 0) {
LAB_23e7eb6b2:
          iVar8 = 0;
          pcVar13 = pcVar22;
          goto LAB_23e7eb6b5;
        }
        iVar8 = 0;
        plVar11 = (longlong *)0x0;
        local_138 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        in_R11 = (longlong *)0x0;
        plVar24 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        local_b8._0_8_ = plVar16;
LAB_23e7eb6f4:
        if (*(longlong **)(pcVar14 + 0x18) == plVar3) goto LAB_23e7ebdf9;
        local_a8 = pcVar14;
        if (iVar8 == 0) {
          iVar8 = (int)plVar3[5];
        }
        goto LAB_23e7ebd40;
      }
      *(longlong **)(param_1 + 0x138) = plVar24;
      *(longlong *)pcVar22 = *(longlong *)pcVar22 + -1;
      if (*(longlong *)pcVar22 == 0) goto LAB_23e7eb6b2;
      local_150 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      local_138 = (longlong *)0x0;
      plVar24 = (longlong *)0x0;
      in_R11 = (longlong *)0x0;
      local_158 = (longlong *)0x0;
      local_b8._0_8_ = plVar16;
LAB_23e7eccb0:
      local_a8 = (code *)0x0;
      iVar8 = (int)plVar3[5];
    }
LAB_23e7ec830:
    pcVar14 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar14 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar13 = local_a8;
    }
    else {
      pcVar13 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar13;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar13 = (code *)0x0;
    }
    *(longlong *)(pcVar14 + 0x10) = 0;
    *(longlong **)(pcVar14 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    *(undefined4 *)(pcVar14 + 0x20) = 0xffffffff;
    lVar20 = *(longlong *)(local_148 + 0x1f8);
    *(int *)(pcVar14 + 0x24) = iVar8;
    lVar20 = *(longlong *)(*(longlong *)(lVar20 + 0x10) + 0x2e8);
    lVar9 = *(longlong *)(pcVar14 + -8);
    puVar1 = *(undefined8 **)(lVar20 + 8);
    *puVar1 = pcVar14 + -0x10;
    *(longlong *)(pcVar14 + -0x10) = lVar20;
    *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar1;
    *(code **)(lVar20 + 8) = pcVar14 + -0x10;
    if ((pcVar13 != (code *)0x0) &&
       (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
      (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
    }
  }
LAB_23e7ebdf9:
  local_a8 = pcVar14;
  FUN_23e8bba40(plVar3,"ooooooo",local_160,plVar24,in_R11,local_138,plVar11,local_158,local_150);
  if (DAT_23eedeb08 == plVar3) {
    lVar20 = *plVar3;
    *plVar3 = lVar20 + -1;
    if (lVar20 + -1 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eedeb08 = (longlong *)0x0;
  }
  lVar20 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar20 + 0x28);
  plVar12 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar20 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pcVar14 = local_a8;
  auVar6 = local_b8;
  uVar10 = local_b8._0_8_;
  uVar26 = local_b8._8_8_;
  plVar3[0xf] = 0;
  local_b8 = (undefined1  [16])0x0;
  local_a8 = (code *)0x0;
  if ((local_160 != (longlong *)0x0) &&
     (lVar20 = *local_160, *local_160 = lVar20 + -1, lVar20 + -1 == 0)) {
    (**(code **)(local_160[1] + 0x30))(local_160);
  }
  if ((plVar24 != (longlong *)0x0) && (*plVar24 = *plVar24 + -1, *plVar24 == 0)) {
    (**(code **)(plVar24[1] + 0x30))(plVar24);
  }
  if ((in_R11 != (longlong *)0x0) && (*in_R11 = *in_R11 + -1, *in_R11 == 0)) {
    (**(code **)(in_R11[1] + 0x30))(in_R11);
  }
  if ((local_138 != (longlong *)0x0) && (*local_138 = *local_138 + -1, *local_138 == 0)) {
    (**(code **)(local_138[1] + 0x30))(local_138);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((local_158 != (longlong *)0x0) &&
     (lVar20 = *local_158, *local_158 = lVar20 + -1, lVar20 + -1 == 0)) {
    (**(code **)(local_158[1] + 0x30))(local_158);
  }
  if ((local_150 != (longlong *)0x0) &&
     (lVar20 = *local_150, *local_150 = lVar20 + -1, lVar20 + -1 == 0)) {
    (**(code **)(local_150[1] + 0x30))(local_150);
  }
  local_b8 = auVar6;
  local_a8 = pcVar14;
  FUN_23a33aa70(param_1,uVar10,uVar26,pcVar14);
  return (longlong *)0x0;
}
