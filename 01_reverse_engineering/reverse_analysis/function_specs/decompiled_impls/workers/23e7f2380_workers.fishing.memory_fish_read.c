/* ===== 23e7f2380 workers.fishing.memory_fish_read:213 ===== */
/* ghidra_name=FUN_23e7f2380 entry=23e7f2380 size=4084 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7f2380(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong *plVar6;
  bool bVar7;
  code *pcVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  undefined8 uVar16;
  longlong *plVar17;
  code *pcVar18;
  code *pcVar19;
  code *pcVar20;
  code *pcVar21;
  code *pcVar22;
  undefined4 uVar23;
  code *pcVar24;
  int local_a0;
  undefined1 local_88 [16];
  code *local_78 [2];
  code *local_68;
  code *local_60;
  code *local_58;
  
  plVar10 = _DAT_23eedeaa0;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedeaa0 == (longlong *)0x0) {
LAB_23e7f23bd:
    _DAT_23eedeaa0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedea98,DAT_23eedebc0,8);
  }
  else {
    lVar2 = *_DAT_23eedeaa0;
    if (1 < lVar2) {
      *_DAT_23eedeaa0 = lVar2 + -1;
      goto LAB_23e7f23bd;
    }
    if (_DAT_23eedeaa0[2] != 0) {
      *_DAT_23eedeaa0 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e7f23bd;
    }
  }
  plVar3 = _DAT_23eedeaa0;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedeaa0 + 9;
  lVar15 = *(longlong *)(lVar2 + 8);
  _DAT_23eedeaa0[0xf] = lVar15;
  *(longlong **)(lVar2 + 8) = plVar10;
  if ((lVar15 != 0) &&
     (((*(char *)(lVar15 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar15 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar15 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar15 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar16 = _DAT_23eedde58;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar16);
  if (plVar10 == (longlong *)0x0) {
    pcVar24 = *(code **)(param_1 + 0x60);
    pcVar22 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar21 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023e7f2dac:
    if (pcVar22 == (code *)0x0) {
LAB_23e7f3170:
      uVar23 = 0xd7;
LAB_23e7f3022:
      pcVar18 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar22 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar22;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar22 = _PyRuntime_exref;
      *(longlong *)(pcVar18 + 0x10) = 0;
      *(longlong **)(pcVar18 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar2 = *(longlong *)(pcVar22 + 0x1f8);
      *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
      lVar2 = *(longlong *)(lVar2 + 0x10);
      *(undefined4 *)(pcVar18 + 0x24) = uVar23;
      lVar2 = *(longlong *)(lVar2 + 0x2e8);
      lVar15 = *(longlong *)(pcVar18 + -8);
      puVar4 = *(undefined8 **)(lVar2 + 8);
      *puVar4 = pcVar18 + -0x10;
      *(longlong *)(pcVar18 + -0x10) = lVar2;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar4;
      *(code **)(lVar2 + 8) = pcVar18 + -0x10;
      goto LAB_23e7f27c0;
    }
    plVar10 = *(longlong **)(pcVar22 + 0x18);
joined_r0x00023e7f2dbc:
    uVar23 = 0xd7;
    pcVar18 = pcVar22;
    if (plVar10 == plVar3) goto LAB_23e7f27c0;
  }
  else {
    plVar11 = (longlong *)FUN_23e8d9880(plVar10,DAT_23ed6cd90);
    if (plVar11 == (longlong *)0x0) {
LAB_23e7f26c4:
      pcVar24 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x68);
      pcVar22 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 != 0) goto joined_r0x00023e7f2dac;
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      if (pcVar22 == (code *)0x0) goto LAB_23e7f3170;
      plVar10 = *(longlong **)(pcVar22 + 0x18);
      goto joined_r0x00023e7f2dbc;
    }
    *(undefined4 *)(plVar3 + 5) = 0xd7;
    plVar12 = (longlong *)FUN_23e91a870(param_1,plVar11);
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23e7f26c4;
    plVar11 = (longlong *)FUN_23e8d9880(plVar10,DAT_23ed6cd98);
    if (plVar11 == (longlong *)0x0) {
      pcVar24 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x68);
      pcVar22 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        local_a0 = 0xd7;
        goto LAB_23e7f2fe8;
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
        local_a0 = 0xd7;
        goto LAB_23e7f2fb2;
      }
      if (pcVar22 != (code *)0x0) {
        pcVar18 = pcVar22;
        if (plVar3 == *(longlong **)(pcVar22 + 0x18)) goto LAB_23e7f27c0;
        goto LAB_23e7f32b3;
      }
      goto LAB_23e7f3170;
    }
    plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde60);
    if (plVar13 == (longlong *)0x0) {
LAB_23e7f2890:
      local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
      local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
      pcVar24 = *(code **)(param_1 + 0x70);
      uVar23 = 0xd8;
LAB_23e7f289e:
      plVar13 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (plVar13 != (longlong *)0x0) {
        *plVar13 = *plVar13 + 1;
      }
      pcVar21 = DAT_23ed6a4f8;
      local_78[0] = pcVar24;
      if (pcVar24 == (code *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar24 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar24;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        pcVar24 = _PyRuntime_exref;
        *(longlong *)(pcVar21 + 0x10) = 0;
        *(longlong **)(pcVar21 + 0x18) = plVar3;
        *plVar3 = *plVar3 + 1;
        lVar2 = *(longlong *)(pcVar24 + 0x1f8);
        *(undefined4 *)(pcVar21 + 0x24) = uVar23;
        lVar2 = *(longlong *)(lVar2 + 0x10);
        *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
        lVar2 = *(longlong *)(lVar2 + 0x2e8);
        lVar15 = *(longlong *)(pcVar21 + -8);
        puVar4 = *(undefined8 **)(lVar2 + 8);
        *puVar4 = pcVar21 + -0x10;
        *(longlong *)(pcVar21 + -0x10) = lVar2;
        *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar4;
        *(code **)(lVar2 + 8) = pcVar21 + -0x10;
        if ((local_78[0] != (code *)0x0) &&
           (*(longlong *)local_78[0] = *(longlong *)local_78[0] + -1, *(longlong *)local_78[0] == 0)
           ) {
          (**(code **)(*(longlong *)(local_78[0] + 8) + 0x30))(local_78[0]);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar22 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar22;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        pcVar22 = _PyRuntime_exref;
        *(longlong **)(pcVar21 + 0x18) = plVar3;
        *plVar3 = *plVar3 + 1;
        lVar2 = *(longlong *)(pcVar22 + 0x1f8);
        *(undefined4 *)(pcVar21 + 0x24) = uVar23;
        *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
        lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
        lVar15 = *(longlong *)(pcVar21 + -8);
        puVar4 = *(undefined8 **)(lVar2 + 8);
        *puVar4 = pcVar21 + -0x10;
        *(longlong *)(pcVar21 + -0x10) = lVar2;
        *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar4;
        *(code **)(lVar2 + 8) = pcVar21 + -0x10;
        *(code **)(pcVar21 + 0x10) = pcVar24;
        *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
        if ((local_78[0] != (code *)0x0) &&
           (*(longlong *)local_78[0] = *(longlong *)local_78[0] + -1, *(longlong *)local_78[0] == 0)
           ) {
          (**(code **)(*(longlong *)(local_78[0] + 8) + 0x30))();
        }
      }
      pcVar24 = _Py_NoneStruct_exref;
      local_78[0] = pcVar21;
      if (((code *)local_88._0_8_ != (code *)0x0) &&
         ((code *)local_88._0_8_ != _Py_NoneStruct_exref)) {
        FUN_23e91b1b0(param_1,local_88,local_88 + 8,local_78);
      }
      plVar14 = *(longlong **)(local_88._8_8_ + 0x28);
      if (local_78[0] == pcVar24) {
        pcVar21 = (code *)0x0;
      }
      else {
        pcVar21 = local_78[0];
        if (local_78[0] != (code *)0x0) {
          *(longlong *)local_78[0] = *(longlong *)local_78[0] + 1;
        }
      }
      *(code **)(local_88._8_8_ + 0x28) = pcVar21;
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))();
      }
      plVar14 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = local_88._8_8_;
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))();
      }
      *(longlong *)local_88._0_8_ = *(longlong *)local_88._0_8_ + -1;
      if (*(longlong *)local_88._0_8_ == 0) {
        (**(code **)(*(longlong *)(local_88._0_8_ + 8) + 0x30))();
      }
      if ((local_78[0] != (code *)0x0) &&
         (*(longlong *)local_78[0] = *(longlong *)local_78[0] + -1, *(longlong *)local_78[0] == 0))
      {
        (**(code **)(*(longlong *)(local_78[0] + 8) + 0x30))();
      }
      pcVar18 = *(code **)(param_1 + 0x138);
      local_78[0] = (code *)0x0;
      local_88 = (undefined1  [16])0x0;
      pcVar21 = *(code **)PyExc_BaseException_exref;
      pcVar22 = *(code **)(pcVar18 + 8);
      if ((*(uint *)(*(longlong *)(pcVar21 + 8) + 0xa8) & 0x4000000) == 0) {
        if (((int)*(uint *)(*(longlong *)(pcVar21 + 8) + 0xa8) < 0) &&
           (((byte)pcVar21[0xab] & 0x40) != 0)) {
          pcVar20 = *(code **)(pcVar22 + 8);
          if ((*(uint *)(pcVar20 + 0xa8) & 0x40000000) == 0) {
            pcVar19 = pcVar22;
            if ((-1 < (int)*(uint *)(pcVar20 + 0xa8)) ||
               (pcVar20 = pcVar22, ((byte)pcVar22[0xab] & 0x40) == 0)) goto LAB_23e7f31b4;
          }
          else {
            pcVar19 = pcVar20;
            if (-1 < *(int *)(*(longlong *)(pcVar20 + 8) + 0xa8)) {
LAB_23e7f31b4:
              if (pcVar21 == pcVar19) goto LAB_23e7f2bfb;
              goto LAB_23e7f2ae3;
            }
          }
          lVar2 = *(longlong *)(pcVar20 + 0x158);
          if (lVar2 == 0) {
            do {
              if (pcVar21 == pcVar20) goto LAB_23e7f2bf7;
              pcVar20 = *(code **)(pcVar20 + 0x100);
            } while (pcVar20 != (code *)0x0);
            if (pcVar21 == PyBaseObject_Type_exref) goto LAB_23e7f2bf7;
          }
          else if (0 < *(longlong *)(lVar2 + 0x10)) {
            lVar15 = 0;
            do {
              if (pcVar21 == *(code **)(lVar2 + 0x18 + lVar15 * 8)) goto LAB_23e7f2bf7;
              lVar15 = lVar15 + 1;
            } while (*(longlong *)(lVar2 + 0x10) != lVar15);
          }
          goto LAB_23e7f2ae3;
        }
LAB_23e7f2b50:
        plVar14 = *(longlong **)PyExc_TypeError_exref;
        uVar16 = PyUnicode_FromString
                           ("catching classes that do not inherit from BaseException is not allowed"
                           );
        plVar5 = *(longlong **)(param_1 + 0x60);
        plVar6 = *(longlong **)(param_1 + 0x70);
        plVar17 = *(longlong **)(param_1 + 0x68);
        *(longlong **)(param_1 + 0x60) = plVar14;
        *plVar14 = *plVar14 + 1;
        *(undefined8 *)(param_1 + 0x68) = uVar16;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
          (**(code **)(plVar5[1] + 0x30))();
        }
        if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        if ((plVar6 == (longlong *)0x0) || (*plVar6 = *plVar6 + -1, *plVar6 != 0)) {
LAB_23e7f2bf0:
          pcVar18 = *(code **)(param_1 + 0x138);
LAB_23e7f2bf7:
          pcVar22 = *(code **)(pcVar18 + 8);
        }
        else {
          (**(code **)(plVar6[1] + 0x30))(plVar6);
          pcVar18 = *(code **)(param_1 + 0x138);
          pcVar22 = *(code **)(pcVar18 + 8);
        }
LAB_23e7f2bfb:
        local_58 = *(code **)(pcVar18 + 0x28);
        *(undefined4 *)(plVar3 + 5) = 0xd7;
        if (local_58 == (code *)0x0) {
          local_58 = pcVar24;
        }
        local_68 = pcVar22;
        local_60 = pcVar18;
        plVar14 = (longlong *)FUN_23e956150(param_1,plVar11,&local_68);
        if (plVar14 == (longlong *)0x0) {
LAB_23e7f2f10:
          pcVar24 = *(code **)(param_1 + 0x60);
          pcVar21 = *(code **)(param_1 + 0x68);
          bVar7 = false;
          pcVar18 = *(code **)(param_1 + 0x138);
          pcVar22 = *(code **)(param_1 + 0x70);
          local_a0 = 0xd7;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(longlong **)(param_1 + 0x138) = plVar13;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar20 = pcVar24;
          pcVar19 = pcVar21;
          pcVar8 = pcVar22;
          if (pcVar18 == (code *)0x0) goto LAB_23e7f2f89;
        }
        else {
          iVar9 = FUN_23a35f020(plVar14);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (iVar9 == -1) goto LAB_23e7f2f10;
          if (iVar9 != 0) {
            plVar14 = *(longlong **)(param_1 + 0x138);
            *(longlong **)(param_1 + 0x138) = plVar13;
            if (plVar14 == (longlong *)0x0) goto LAB_23e7f2600;
            *plVar14 = *plVar14 + -1;
            lVar2 = *plVar14;
joined_r0x00023e7f2c7e:
            if (lVar2 == 0) {
              (**(code **)(plVar14[1] + 0x30))();
            }
LAB_23e7f2600:
            lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar3 = *(longlong **)(lVar2 + 0x28);
            plVar13 = (longlong *)plVar3[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
            *(undefined4 *)(plVar3 + 8) = 0xffffffff;
            if (plVar13 != (longlong *)0x0) {
              plVar3[2] = 0;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))();
              }
            }
            *plVar3 = *plVar3 + -1;
            if (*plVar3 == 0) {
              (**(code **)(plVar3[1] + 0x30))(plVar3);
            }
            plVar3[0xf] = 0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
            *plVar1 = *plVar1 + -1;
            if (*plVar1 != 0) {
              return pcVar24;
            }
            (**(code **)(plVar1[1] + 0x30))(plVar1);
            return pcVar24;
          }
          pcVar18 = *(code **)(param_1 + 0x138);
          bVar7 = false;
          if ((pcVar18 == (code *)0x0) || (pcVar18 == pcVar24)) {
            pcVar22 = *(code **)PyExc_RuntimeError_exref;
            pcVar24 = pcVar22;
            pcVar21 = (code *)PyUnicode_FromString("No active exception to reraise");
            pcVar18 = *(code **)(param_1 + 0x138);
            *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
            *(longlong **)(param_1 + 0x138) = plVar13;
            if (pcVar18 == (code *)0x0) {
              local_58 = (code *)0x0;
              local_a0 = 0xd7;
              pcVar22 = (code *)0x0;
              pcVar20 = pcVar24;
              pcVar19 = pcVar21;
              pcVar8 = local_58;
              goto LAB_23e7f2f89;
            }
            local_a0 = 0xd7;
            pcVar22 = (code *)0x0;
          }
          else {
            pcVar24 = *(code **)(pcVar18 + 8);
            pcVar22 = *(code **)(pcVar18 + 0x28);
            *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
            *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
            if ((pcVar22 != (code *)0x0) &&
               (*(longlong *)pcVar22 = *(longlong *)pcVar22 + 1,
               plVar3 == *(longlong **)(pcVar22 + 0x18))) {
              *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar22 + 0x24);
            }
            local_a0 = 0;
            *(longlong **)(param_1 + 0x138) = plVar13;
            pcVar21 = pcVar18;
          }
        }
LAB_23e7f2f57:
        *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
        if (*(longlong *)pcVar18 == 0) {
          (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
        }
        pcVar20 = pcVar24;
        pcVar19 = pcVar21;
        local_60 = pcVar21;
        pcVar8 = pcVar22;
        local_58 = pcVar22;
        if (!bVar7) goto LAB_23e7f2f89;
      }
      else {
        lVar2 = *(longlong *)(pcVar21 + 0x10);
        if (0 < lVar2) {
          lVar15 = 0;
          do {
            if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar21 + lVar15 * 8 + 0x18) + 8) + 0xa8)
                ) || ((*(byte *)(*(longlong *)(pcVar21 + lVar15 * 8 + 0x18) + 0xab) & 0x40) == 0))
            goto LAB_23e7f2b50;
            lVar15 = lVar15 + 1;
          } while (lVar2 != lVar15);
          lVar15 = 0;
          do {
            iVar9 = FUN_23a35ebd0(param_1,pcVar22,*(undefined8 *)(pcVar21 + lVar15 * 8 + 0x18),
                                  pcVar21,pcVar22);
            if (iVar9 != 0) goto LAB_23e7f2bf0;
            lVar15 = lVar15 + 1;
          } while (lVar2 != lVar15);
          pcVar18 = *(code **)(param_1 + 0x138);
        }
LAB_23e7f2ae3:
        if ((pcVar18 != pcVar24) && (pcVar18 != (code *)0x0)) {
          pcVar24 = *(code **)(pcVar18 + 8);
          pcVar22 = *(code **)(pcVar18 + 0x28);
          *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
          *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
          if ((pcVar22 != (code *)0x0) &&
             (*(longlong *)pcVar22 = *(longlong *)pcVar22 + 1,
             plVar3 == *(longlong **)(pcVar22 + 0x18))) {
            *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar22 + 0x24);
          }
          local_a0 = 0;
          bVar7 = true;
          *(longlong **)(param_1 + 0x138) = plVar13;
          pcVar21 = pcVar18;
          goto LAB_23e7f2f57;
        }
        pcVar22 = *(code **)PyExc_RuntimeError_exref;
        pcVar24 = pcVar22;
        pcVar21 = (code *)PyUnicode_FromString("No active exception to reraise");
        pcVar18 = *(code **)(param_1 + 0x138);
        *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
        *(longlong **)(param_1 + 0x138) = plVar13;
        if (pcVar18 != (code *)0x0) {
          local_a0 = 0xd7;
          pcVar22 = (code *)0x0;
          bVar7 = true;
          goto LAB_23e7f2f57;
        }
        local_58 = (code *)0x0;
        local_a0 = 0xd7;
        local_60 = pcVar21;
      }
      *(undefined4 *)(plVar3 + 5) = 0xd7;
      local_68 = pcVar24;
      plVar13 = (longlong *)FUN_23e957a30(param_1,plVar11,DAT_23eedde28);
      if (plVar13 == (longlong *)0x0) {
        pcVar22 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar24 = *(code **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        FUN_23a35d6b0(&local_68);
        local_a0 = 0xd7;
        pcVar20 = local_68;
        pcVar19 = local_60;
        pcVar8 = local_58;
      }
      else {
        *plVar13 = *plVar13 + -1;
        pcVar21 = local_60;
        pcVar22 = local_58;
        pcVar24 = local_68;
        pcVar20 = local_68;
        pcVar19 = local_60;
        pcVar8 = local_58;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
          pcVar21 = local_60;
          pcVar22 = local_58;
          pcVar24 = local_68;
          pcVar20 = local_68;
          pcVar19 = local_60;
          pcVar8 = local_58;
        }
      }
    }
    else {
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,_DAT_23eeddec0);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (plVar14 == (longlong *)0x0) goto LAB_23e7f2890;
      *(undefined4 *)(plVar3 + 5) = 0xd8;
      plVar13 = (longlong *)FUN_23e91a870(param_1,plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar13 == (longlong *)0x0) goto LAB_23e7f2890;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedde80);
      if (plVar13 == (longlong *)0x0) {
LAB_23e7f2ea8:
        local_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
        pcVar24 = *(code **)(param_1 + 0x70);
        uVar23 = 0xd9;
        goto LAB_23e7f289e;
      }
      plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,_DAT_23eeddec0);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (plVar14 == (longlong *)0x0) goto LAB_23e7f2ea8;
      *(undefined4 *)(plVar3 + 5) = 0xd9;
      plVar13 = (longlong *)FUN_23e91a870(param_1,plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar13 == (longlong *)0x0) goto LAB_23e7f2ea8;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      *(undefined4 *)(plVar3 + 5) = 0xd7;
      plVar14 = (longlong *)FUN_23e957a30(param_1,plVar11,DAT_23eedde28);
      if (plVar14 != (longlong *)0x0) {
        *plVar14 = *plVar14 + -1;
        lVar2 = *plVar14;
        pcVar24 = _Py_NoneStruct_exref;
        goto joined_r0x00023e7f2c7e;
      }
      pcVar24 = *(code **)(param_1 + 0x60);
      local_a0 = 0xd7;
      pcVar22 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar21 = *(code **)(param_1 + 0x68);
      pcVar20 = local_68;
      pcVar19 = local_60;
      pcVar8 = local_58;
    }
LAB_23e7f2f89:
    local_58 = pcVar8;
    local_60 = pcVar19;
    local_68 = pcVar20;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
LAB_23e7f2fe8:
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) goto LAB_23e7f2ff8;
LAB_23e7f3002:
      if (plVar11 != (longlong *)0x0) goto LAB_23e7f2fa0;
    }
    else {
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
LAB_23e7f2ff8:
        (**(code **)(plVar12[1] + 0x30))(plVar12);
        goto LAB_23e7f3002;
      }
LAB_23e7f2fa0:
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
LAB_23e7f2fb2:
    if (pcVar22 == (code *)0x0) {
      uVar23 = 0xd7;
      if (local_a0 == 0) {
        uVar23 = (undefined4)plVar3[5];
      }
      goto LAB_23e7f3022;
    }
    pcVar18 = pcVar22;
    if (*(longlong **)(pcVar22 + 0x18) == plVar3) goto LAB_23e7f27c0;
    if (local_a0 == 0) {
      uVar23 = (undefined4)plVar3[5];
    }
    else {
LAB_23e7f32b3:
      uVar23 = 0xd7;
    }
  }
  pcVar18 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar20 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar20;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  pcVar20 = _PyRuntime_exref;
  *(longlong **)(pcVar18 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  lVar2 = *(longlong *)(pcVar20 + 0x1f8);
  *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
  *(undefined4 *)(pcVar18 + 0x24) = uVar23;
  lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
  lVar15 = *(longlong *)(pcVar18 + -8);
  puVar4 = *(undefined8 **)(lVar2 + 8);
  *puVar4 = pcVar18 + -0x10;
  *(longlong *)(pcVar18 + -0x10) = lVar2;
  *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar4;
  lVar15 = *(longlong *)pcVar22;
  *(code **)(lVar2 + 8) = pcVar18 + -0x10;
  *(code **)(pcVar18 + 0x10) = pcVar22;
  if (lVar15 == 0) {
    (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
  }
LAB_23e7f27c0:
  FUN_23e8bba40(plVar3,&DAT_23ec5e2bc,plVar1);
  if (_DAT_23eedeaa0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedeaa0 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar2 + 0x28);
  plVar3 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,pcVar24,pcVar21,pcVar18);
  return (code *)0x0;
}
