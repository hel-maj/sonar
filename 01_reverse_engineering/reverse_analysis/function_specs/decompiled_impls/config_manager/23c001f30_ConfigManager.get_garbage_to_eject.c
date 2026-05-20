/* ===== 23c001f30 config_manager:134 ===== */
/* ghidra_name=FUN_23c001f30 entry=23c001f30 size=6880 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23c001f30(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined1 (*pauVar1) [16];
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined1 auVar7 [16];
  bool bVar8;
  undefined8 uVar9;
  code *pcVar10;
  int iVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong lVar20;
  code *pcVar21;
  undefined8 uVar22;
  code *pcVar23;
  code *pcVar24;
  longlong *plVar25;
  code *pcVar26;
  code *pcVar27;
  code *pcVar28;
  undefined4 uVar29;
  longlong *local_118;
  code *local_110;
  code *local_108;
  code *local_e8;
  undefined8 uStack_e0;
  undefined1 local_d8 [16];
  code *local_c8 [2];
  undefined1 local_b8 [16];
  code *local_a8;
  undefined8 local_98;
  undefined8 uStack_90;
  longlong *local_88;
  code *local_78;
  code *pcStack_70;
  code *local_68;
  
  plVar12 = _DAT_23ee0b5f0;
  plVar3 = (longlong *)*param_3;
  plVar4 = (longlong *)param_3[1];
  if (_DAT_23ee0b5f0 == (longlong *)0x0) {
LAB_23c001f79:
    _DAT_23ee0b5f0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee0b5e8,DAT_23ee0b670,0x20);
  }
  else {
    lVar16 = *_DAT_23ee0b5f0;
    if (1 < lVar16) {
      *_DAT_23ee0b5f0 = lVar16 + -1;
      goto LAB_23c001f79;
    }
    if (_DAT_23ee0b5f0[2] != 0) {
      *_DAT_23ee0b5f0 = lVar16 + -1;
      if (lVar16 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23c001f79;
    }
  }
  plVar6 = _DAT_23ee0b5f0;
  lVar16 = *(longlong *)(param_1 + 0x38);
  plVar12 = _DAT_23ee0b5f0 + 9;
  lVar20 = *(longlong *)(lVar16 + 8);
  _DAT_23ee0b5f0[0xf] = lVar20;
  *(longlong **)(lVar16 + 8) = plVar12;
  if ((lVar20 != 0) &&
     (((*(char *)(lVar20 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar20 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar20 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar20 + 0x38))) && (plVar6[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar20 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  uVar22 = _DAT_23ee075a8;
  *(undefined4 *)(plVar6 + 8) = 0;
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar3,uVar22);
  if (plVar12 != (longlong *)0x0) {
    plVar13 = (longlong *)FUN_23e91c870(param_1,plVar12,DAT_23ed6ce88,DAT_23ee075c0);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar13 == (longlong *)0x0) {
      local_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_c8[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_118 = *(longlong **)(param_1 + 0x138);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (local_118 != (longlong *)0x0) {
        *local_118 = *local_118 + 1;
        pcVar23 = _Py_NoneStruct_exref;
        goto joined_r0x00023c003198;
      }
      plVar12 = (longlong *)0x0;
      pcVar23 = _Py_NoneStruct_exref;
      if (local_c8[0] == (code *)0x0) goto LAB_23c002c42;
LAB_23c002371:
      pcVar21 = local_c8[0];
      pcVar24 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar26 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar26;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar24 + 0x18) = plVar6;
      *plVar6 = *plVar6 + 1;
      *(longlong *)(pcVar24 + 0x20) = 0x89ffffffff;
      lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar20 = *(longlong *)(pcVar24 + -8);
      puVar5 = *(undefined8 **)(lVar16 + 8);
      *puVar5 = pcVar24 + -0x10;
      *(longlong *)(pcVar24 + -0x10) = lVar16;
      *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar5;
      *(code **)(lVar16 + 8) = pcVar24 + -0x10;
      *(code **)(pcVar24 + 0x10) = pcVar21;
      *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
      plVar14 = plVar12;
      if (local_c8[0] != (code *)0x0) {
        *(longlong *)local_c8[0] = *(longlong *)local_c8[0] + -1;
        lVar16 = *(longlong *)local_c8[0];
        pcVar21 = local_c8[0];
        goto joined_r0x00023c0026ed;
      }
      goto LAB_23c00240c;
    }
    plVar12 = (longlong *)FUN_23e8d9880(plVar13,DAT_23ed6cd90);
    if (plVar12 == (longlong *)0x0) {
LAB_23c002a30:
      pauVar1 = (undefined1 (*) [16])(param_1 + 0x60);
      pcVar21 = *(code **)*pauVar1;
      local_d8 = *pauVar1;
      auVar7 = *pauVar1;
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      local_c8[0] = pcVar24;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
        local_118 = *(longlong **)(param_1 + 0x138);
        if (local_118 != (longlong *)0x0) {
          local_108._0_4_ = 0x89;
          plVar12 = (longlong *)0x0;
          pcVar23 = _Py_NoneStruct_exref;
          local_d8 = auVar7;
LAB_23c002bfe:
          *local_118 = *local_118 + 1;
          local_c8[0] = pcVar24;
          goto LAB_23c002c07;
        }
      }
      else {
        local_118 = *(longlong **)(param_1 + 0x138);
        if (local_118 != (longlong *)0x0) {
          *local_118 = *local_118 + 1;
          pcVar23 = _Py_NoneStruct_exref;
          goto joined_r0x00023c003198;
        }
      }
      local_d8 = *pauVar1;
      if (pcVar24 == (code *)0x0) goto LAB_23c002c42;
      plVar12 = (longlong *)0x0;
      pcVar23 = _Py_NoneStruct_exref;
      goto LAB_23c002371;
    }
    *(undefined4 *)(plVar6 + 5) = 0x89;
    plVar14 = (longlong *)FUN_23e91a870(param_1,plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar14 == (longlong *)0x0) goto LAB_23c002a30;
    plVar15 = (longlong *)FUN_23e8d9880(plVar13,DAT_23ed6cd98);
    if (plVar15 == (longlong *)0x0) {
      pcVar24 = *(code **)(param_1 + 0x70);
      pcVar21 = *(code **)(param_1 + 0x60);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar23 = _Py_NoneStruct_exref;
      local_108._0_4_ = 0x89;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar12 = (longlong *)0x0;
      pcVar26 = *(code **)(param_1 + 0x68);
      pcVar2 = local_78;
      pcVar28 = pcStack_70;
      pcVar10 = local_68;
LAB_23c002b7a:
      local_68 = pcVar10;
      pcStack_70 = pcVar28;
      local_78 = pcVar2;
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      lVar16 = *plVar14;
      *plVar14 = lVar16 + -1;
      if (lVar16 + -1 == 0) {
        (**(code **)(plVar14[1] + 0x30))();
      }
      if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      local_118 = *(longlong **)(param_1 + 0x138);
      local_d8._8_8_ = pcVar26;
      local_d8._0_8_ = pcVar21;
      local_c8[0] = pcVar24;
      if (local_118 != (longlong *)0x0) goto LAB_23c002bfe;
LAB_23c002c07:
      if (local_c8[0] == (code *)0x0) {
        if ((int)local_108 == 0) {
          uVar29 = (undefined4)plVar6[5];
        }
        else {
          uVar29 = 0x89;
        }
        goto LAB_23c002655;
      }
      plVar14 = plVar12;
      if ((int)local_108 != 0) goto LAB_23c002371;
      goto LAB_23c002419;
    }
    *plVar14 = *plVar14 + 1;
    lVar16 = FUN_23eb1ba00();
    plVar12 = plVar14;
    if (lVar16 == 0) {
      FUN_23e915740(param_1,&local_98,DAT_23ee075c8);
      local_110 = _PyRuntime_exref;
      plVar17 = local_88;
LAB_23c003335:
      plVar25 = *(longlong **)(param_1 + 0x138);
      local_b8._8_8_ = uStack_90;
      local_b8._0_8_ = local_98;
      if (plVar25 != (longlong *)0x0) {
        *plVar25 = *plVar25 + 1;
      }
      pcVar24 = DAT_23ed6a4f8;
      local_a8 = (code *)plVar17;
      if (plVar17 == (longlong *)0x0) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar23 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar23;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar24 + 0x18) = plVar6;
        *(longlong *)(pcVar24 + 0x10) = 0;
        *plVar6 = *plVar6 + 1;
        *(longlong *)(pcVar24 + 0x20) = 0x8affffffff;
        lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(local_110 + 0x1f8) + 0x10) + 0x2e8);
        lVar20 = *(longlong *)(pcVar24 + -8);
        puVar5 = *(undefined8 **)(lVar16 + 8);
        *puVar5 = pcVar24 + -0x10;
        *(longlong *)(pcVar24 + -0x10) = lVar16;
        *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar5;
        *(code **)(lVar16 + 8) = pcVar24 + -0x10;
        if ((local_a8 != (code *)0x0) &&
           (*(longlong *)local_a8 = *(longlong *)local_a8 + -1, *(longlong *)local_a8 == 0)) {
          (**(code **)(*(longlong *)((longlong)local_a8 + 8) + 0x30))(local_a8);
        }
      }
      else {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar23 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar23;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar24 + 0x18) = plVar6;
        *plVar6 = *plVar6 + 1;
        *(longlong *)(pcVar24 + 0x20) = 0x8affffffff;
        lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(local_110 + 0x1f8) + 0x10) + 0x2e8);
        lVar20 = *(longlong *)(pcVar24 + -8);
        puVar5 = *(undefined8 **)(lVar16 + 8);
        *puVar5 = pcVar24 + -0x10;
        *(longlong *)(pcVar24 + -0x10) = lVar16;
        *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar5;
        *(code **)(lVar16 + 8) = pcVar24 + -0x10;
        *(longlong **)(pcVar24 + 0x10) = plVar17;
        *plVar17 = *plVar17 + 1;
        if ((local_a8 != (code *)0x0) &&
           (*(longlong *)local_a8 = *(longlong *)local_a8 + -1, *(longlong *)local_a8 == 0)) {
          (**(code **)(*(longlong *)((longlong)local_a8 + 8) + 0x30))();
        }
      }
      pcVar23 = _Py_NoneStruct_exref;
      local_a8 = pcVar24;
      if (((code *)local_b8._0_8_ != _Py_NoneStruct_exref) &&
         ((code *)local_b8._0_8_ != (code *)0x0)) {
        FUN_23e91b1b0(param_1,local_b8,local_b8 + 8);
      }
      plVar17 = *(longlong **)(local_b8._8_8_ + 0x28);
      if (local_a8 == pcVar23) {
        pcVar24 = (code *)0x0;
      }
      else {
        pcVar24 = local_a8;
        if (local_a8 != (code *)0x0) {
          *(longlong *)local_a8 = *(longlong *)local_a8 + 1;
        }
      }
      *(code **)(local_b8._8_8_ + 0x28) = pcVar24;
      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
        (**(code **)(plVar17[1] + 0x30))();
      }
      plVar17 = *(longlong **)(param_1 + 0x138);
      *(undefined8 *)(param_1 + 0x138) = local_b8._8_8_;
      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
        (**(code **)(plVar17[1] + 0x30))();
      }
      *(longlong *)local_b8._0_8_ = *(longlong *)local_b8._0_8_ + -1;
      if (*(longlong *)local_b8._0_8_ == 0) {
        (**(code **)(*(longlong *)(local_b8._0_8_ + 8) + 0x30))();
      }
      if ((local_a8 != (code *)0x0) &&
         (*(longlong *)local_a8 = *(longlong *)local_a8 + -1, *(longlong *)local_a8 == 0)) {
        (**(code **)(*(longlong *)(local_a8 + 8) + 0x30))();
      }
      local_a8 = (code *)0x0;
      local_b8 = (undefined1  [16])0x0;
      iVar11 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                             *(undefined8 *)PyExc_BaseException_exref);
      if (iVar11 == 0) {
        pcVar27 = *(code **)(param_1 + 0x138);
        if ((pcVar27 != pcVar23) && (pcVar27 != (code *)0x0)) {
          pcVar21 = *(code **)(pcVar27 + 8);
          pcVar24 = *(code **)(pcVar27 + 0x28);
          *(longlong *)pcVar27 = *(longlong *)pcVar27 + 1;
          *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
          if ((pcVar24 != (code *)0x0) &&
             (*(longlong *)pcVar24 = *(longlong *)pcVar24 + 1,
             plVar6 == *(longlong **)(pcVar24 + 0x18))) {
            *(undefined4 *)(plVar6 + 5) = *(undefined4 *)(pcVar24 + 0x24);
          }
          *(longlong **)(param_1 + 0x138) = plVar25;
          bVar8 = true;
          local_108._0_4_ = 0;
          pcVar26 = pcVar27;
          goto LAB_23c003600;
        }
        pcVar21 = *(code **)PyExc_RuntimeError_exref;
        pcVar26 = (code *)PyUnicode_FromString("No active exception to reraise");
        pcVar27 = *(code **)(param_1 + 0x138);
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
        *(longlong **)(param_1 + 0x138) = plVar25;
        if (pcVar27 != (code *)0x0) {
          local_108._0_4_ = 0x89;
          pcVar24 = (code *)0x0;
          bVar8 = true;
          goto LAB_23c003600;
        }
        local_68 = (code *)0x0;
        local_108._0_4_ = 0x89;
        local_78 = pcVar21;
        pcStack_70 = pcVar26;
      }
      else {
        pcStack_70 = *(code **)(param_1 + 0x138);
        local_78 = *(code **)(pcStack_70 + 8);
        local_68 = *(code **)(pcStack_70 + 0x28);
        *(undefined4 *)(plVar6 + 5) = 0x89;
        if (local_68 == (code *)0x0) {
          local_68 = pcVar23;
        }
        plVar17 = (longlong *)FUN_23e956150(param_1,plVar15,&local_78);
        if (plVar17 == (longlong *)0x0) {
          pcVar24 = *(code **)(param_1 + 0x70);
          pcVar21 = *(code **)(param_1 + 0x60);
          pcVar26 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          iVar11 = FUN_23a35f020(plVar17);
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))();
          }
          if (iVar11 != -1) {
            if (iVar11 == 0) {
              pcVar27 = *(code **)(param_1 + 0x138);
              bVar8 = false;
              if ((pcVar27 == pcVar23) || (pcVar27 == (code *)0x0)) {
                pcVar21 = *(code **)PyExc_RuntimeError_exref;
                pcVar26 = (code *)PyUnicode_FromString("No active exception to reraise");
                pcVar27 = *(code **)(param_1 + 0x138);
                *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
                *(longlong **)(param_1 + 0x138) = plVar25;
                if (pcVar27 == (code *)0x0) {
                  local_68 = (code *)0x0;
                  local_108._0_4_ = 0x89;
                  pcVar24 = local_68;
                  pcVar2 = pcVar21;
                  pcVar28 = pcVar26;
                  pcVar10 = local_68;
                  goto LAB_23c002b7a;
                }
                local_108._0_4_ = 0x89;
                pcVar24 = (code *)0x0;
              }
              else {
                pcVar21 = *(code **)(pcVar27 + 8);
                pcVar24 = *(code **)(pcVar27 + 0x28);
                *(longlong *)pcVar27 = *(longlong *)pcVar27 + 1;
                *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
                pcVar26 = pcVar27;
                if ((pcVar24 == (code *)0x0) ||
                   (*(longlong *)pcVar24 = *(longlong *)pcVar24 + 1,
                   plVar6 != *(longlong **)(pcVar24 + 0x18))) {
                  *(longlong **)(param_1 + 0x138) = plVar25;
                  local_108._0_4_ = 0;
                }
                else {
                  local_108._0_4_ = 0;
                  *(undefined4 *)(plVar6 + 5) = *(undefined4 *)(pcVar24 + 0x24);
                  *(longlong **)(param_1 + 0x138) = plVar25;
                }
              }
              goto LAB_23c003600;
            }
            plVar17 = *(longlong **)(param_1 + 0x138);
            *(longlong **)(param_1 + 0x138) = plVar25;
            if (plVar17 != (longlong *)0x0) goto LAB_23c002230;
            goto LAB_23c00223d;
          }
          pcVar21 = *(code **)(param_1 + 0x60);
          pcVar26 = *(code **)(param_1 + 0x68);
          pcVar24 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        pcVar27 = *(code **)(param_1 + 0x138);
        *(undefined8 *)(param_1 + 0x70) = 0;
        bVar8 = false;
        *(longlong **)(param_1 + 0x138) = plVar25;
        local_108._0_4_ = 0x89;
        pcVar2 = pcVar21;
        pcVar28 = pcVar26;
        pcVar10 = pcVar24;
        if (pcVar27 == (code *)0x0) goto LAB_23c002b7a;
LAB_23c003600:
        *(longlong *)pcVar27 = *(longlong *)pcVar27 + -1;
        if (*(longlong *)pcVar27 == 0) {
          (**(code **)(*(longlong *)(pcVar27 + 8) + 0x30))();
        }
        local_78 = pcVar21;
        pcVar2 = pcVar21;
        pcStack_70 = pcVar26;
        pcVar28 = pcVar26;
        local_68 = pcVar24;
        pcVar10 = pcVar24;
        if (!bVar8) goto LAB_23c002b7a;
      }
      *(undefined4 *)(plVar6 + 5) = 0x89;
      plVar17 = (longlong *)FUN_23e957a30(param_1,plVar15,DAT_23ee075f8);
      if (plVar17 == (longlong *)0x0) {
        pcVar24 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar21 = *(code **)(param_1 + 0x60);
        pcVar26 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        FUN_23a35d6b0(&local_78);
        local_108._0_4_ = 0x89;
        pcVar2 = local_78;
        pcVar28 = pcStack_70;
        pcVar10 = local_68;
      }
      else {
        *plVar17 = *plVar17 + -1;
        pcVar24 = local_68;
        pcVar21 = local_78;
        pcVar26 = pcStack_70;
        pcVar2 = local_78;
        pcVar28 = pcStack_70;
        pcVar10 = local_68;
        if (*plVar17 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
          pcVar24 = local_68;
          pcVar21 = local_78;
          pcVar26 = pcStack_70;
          pcVar2 = local_78;
          pcVar28 = pcStack_70;
          pcVar10 = local_68;
        }
      }
      goto LAB_23c002b7a;
    }
    plVar17 = (longlong *)FUN_23e8bc2f0(lVar16,_DAT_23ee07618);
    local_110 = _PyRuntime_exref;
    if (plVar17 == (longlong *)0x0) {
      plVar17 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_98 = *(undefined8 *)(param_1 + 0x60);
      uStack_90 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c003335;
    }
    lVar16 = *(longlong *)(param_1 + 0x10);
    plVar25 = *(longlong **)(lVar16 + 0xe20);
    if (plVar25 == (longlong *)0x0) {
      plVar25 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar20 = plVar25[3];
      *(int *)(lVar16 + 0xebc) = *(int *)(lVar16 + 0xebc) + -1;
      *(longlong *)(lVar16 + 0xe20) = lVar20;
      *plVar25 = 1;
    }
    local_110 = _PyRuntime_exref;
    lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar20 = plVar25[-1];
    puVar5 = *(undefined8 **)(lVar16 + 8);
    *puVar5 = plVar25 + -2;
    plVar25[-2] = lVar16;
    plVar25[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar16 + 8) = plVar25 + -2;
    uVar22 = _DAT_23ee07620;
    *plVar4 = *plVar4 + 1;
    plVar25[3] = (longlong)plVar4;
    *plVar14 = *plVar14 + 1;
    plVar25[4] = (longlong)plVar14;
    plVar18 = (longlong *)FUN_23e8d7870(param_1,uVar22);
    *(undefined4 *)(plVar6 + 5) = 0x8a;
    plVar19 = (longlong *)FUN_23a334c60(param_1,plVar17,plVar25,plVar18);
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    *plVar25 = *plVar25 + -1;
    if (*plVar25 == 0) {
      (**(code **)(plVar25[1] + 0x30))(plVar25);
    }
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    if (plVar19 == (longlong *)0x0) {
      local_98 = *(undefined8 *)(param_1 + 0x60);
      uStack_90 = *(undefined8 *)(param_1 + 0x68);
      plVar17 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c003335;
    }
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    *(undefined4 *)(plVar6 + 5) = 0x89;
    plVar17 = (longlong *)FUN_23e957a30(param_1,plVar15,DAT_23ee075f8);
    pcVar23 = _Py_NoneStruct_exref;
    if (plVar17 == (longlong *)0x0) {
      pcVar21 = *(code **)(param_1 + 0x60);
      pcVar24 = *(code **)(param_1 + 0x70);
      local_108._0_4_ = 0x89;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar26 = *(code **)(param_1 + 0x68);
      pcVar2 = local_78;
      pcVar28 = pcStack_70;
      pcVar10 = local_68;
      goto LAB_23c002b7a;
    }
LAB_23c002230:
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))();
    }
LAB_23c00223d:
    lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar12 = *(longlong **)(lVar16 + 0x28);
    plVar6 = (longlong *)plVar12[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar16 + 0x30);
    *(undefined4 *)(plVar12 + 8) = 0xffffffff;
    if (plVar6 != (longlong *)0x0) {
      plVar12[2] = 0;
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))();
      }
    }
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    plVar12[0xf] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    lVar16 = *plVar14;
    *plVar14 = lVar16 + -1;
    if (lVar16 + -1 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    pcVar23 = _Py_TrueStruct_exref;
    *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
LAB_23c0029cf:
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
LAB_23c0029d9:
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
      return pcVar23;
    }
    return pcVar23;
  }
  local_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
  local_c8[0] = *(code **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  local_118 = *(longlong **)(param_1 + 0x138);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  if (local_118 == (longlong *)0x0) {
    if (local_c8[0] != (code *)0x0) goto LAB_23c00236a;
LAB_23c002c42:
    plVar12 = (longlong *)0x0;
    uVar29 = 0x89;
    local_118 = (longlong *)0x0;
    pcVar23 = _Py_NoneStruct_exref;
  }
  else {
    *local_118 = *local_118 + 1;
    pcVar23 = _Py_NoneStruct_exref;
joined_r0x00023c003198:
    _Py_NoneStruct_exref = pcVar23;
    if (local_c8[0] != (code *)0x0) {
LAB_23c00236a:
      plVar12 = (longlong *)0x0;
      pcVar23 = _Py_NoneStruct_exref;
      goto LAB_23c002371;
    }
    plVar12 = (longlong *)0x0;
    uVar29 = 0x89;
  }
LAB_23c002655:
  pcVar24 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar24 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    pcVar21 = local_c8[0];
  }
  else {
    pcVar21 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar21;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    pcVar21 = (code *)0x0;
  }
  pcVar26 = _PyRuntime_exref;
  *(longlong *)(pcVar24 + 0x10) = 0;
  *(longlong **)(pcVar24 + 0x18) = plVar6;
  *plVar6 = *plVar6 + 1;
  lVar16 = *(longlong *)(pcVar26 + 0x1f8);
  *(undefined4 *)(pcVar24 + 0x20) = 0xffffffff;
  lVar16 = *(longlong *)(lVar16 + 0x10);
  *(undefined4 *)(pcVar24 + 0x24) = uVar29;
  lVar16 = *(longlong *)(lVar16 + 0x2e8);
  lVar20 = *(longlong *)(pcVar24 + -8);
  puVar5 = *(undefined8 **)(lVar16 + 8);
  *puVar5 = pcVar24 + -0x10;
  *(longlong *)(pcVar24 + -0x10) = lVar16;
  *(ulonglong *)(pcVar24 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar5;
  *(code **)(lVar16 + 8) = pcVar24 + -0x10;
  plVar14 = plVar12;
  if (pcVar21 != (code *)0x0) {
    *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
    lVar16 = *(longlong *)pcVar21;
joined_r0x00023c0026ed:
    plVar14 = plVar12;
    if (lVar16 == 0) {
      (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))();
    }
  }
LAB_23c00240c:
  pcVar21 = (code *)local_d8._0_8_;
  local_c8[0] = pcVar24;
LAB_23c002419:
  if ((pcVar21 != (code *)0x0) && (pcVar21 != pcVar23)) {
    FUN_23e91b1b0(param_1,local_d8,local_d8 + 8,local_c8);
  }
  plVar12 = *(longlong **)(local_d8._8_8_ + 0x28);
  if (local_c8[0] == pcVar23) {
    pcVar24 = (code *)0x0;
  }
  else {
    pcVar24 = local_c8[0];
    if (local_c8[0] != (code *)0x0) {
      *(longlong *)local_c8[0] = *(longlong *)local_c8[0] + 1;
    }
  }
  *(code **)(local_d8._8_8_ + 0x28) = pcVar24;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))();
  }
  plVar12 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = local_d8._8_8_;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))();
  }
  *(longlong *)local_d8._0_8_ = *(longlong *)local_d8._0_8_ + -1;
  if (*(longlong *)local_d8._0_8_ == 0) {
    (**(code **)(*(longlong *)(local_d8._0_8_ + 8) + 0x30))();
  }
  if ((local_c8[0] != (code *)0x0) &&
     (*(longlong *)local_c8[0] = *(longlong *)local_c8[0] + -1, *(longlong *)local_c8[0] == 0)) {
    (**(code **)(*(longlong *)(local_c8[0] + 8) + 0x30))();
  }
  pcVar26 = *(code **)(param_1 + 0x138);
  local_c8[0] = (code *)0x0;
  local_d8 = (undefined1  [16])0x0;
  pcVar24 = *(code **)PyExc_Exception_exref;
  pcVar21 = *(code **)(pcVar26 + 8);
  if ((*(uint *)(*(longlong *)(pcVar24 + 8) + 0xa8) & 0x4000000) == 0) {
    if (((int)*(uint *)(*(longlong *)(pcVar24 + 8) + 0xa8) < 0) &&
       (((byte)pcVar24[0xab] & 0x40) != 0)) {
      pcVar28 = *(code **)(pcVar21 + 8);
      pcVar2 = pcVar28 + 0xa8;
      if ((*(uint *)pcVar2 & 0x40000000) == 0) {
        pcVar28 = pcVar21;
        if ((-1 < (int)*(uint *)pcVar2) || (((byte)pcVar21[0xab] & 0x40) == 0)) goto LAB_23c0031f1;
      }
      else {
        pcVar21 = pcVar28;
        if (-1 < *(int *)(*(longlong *)(pcVar28 + 8) + 0xa8)) {
LAB_23c0031f1:
          if (pcVar28 != pcVar24) goto LAB_23c002592;
          goto LAB_23c0027e4;
        }
      }
      lVar16 = *(longlong *)(pcVar21 + 0x158);
      if (lVar16 == 0) {
        do {
          if (pcVar24 == pcVar21) goto LAB_23c0027e4;
          pcVar21 = *(code **)(pcVar21 + 0x100);
        } while (pcVar21 != (code *)0x0);
        if (pcVar24 == PyBaseObject_Type_exref) goto LAB_23c0027e4;
      }
      else if (0 < *(longlong *)(lVar16 + 0x10)) {
        lVar20 = 0;
        do {
          if (pcVar24 == *(code **)(lVar16 + 0x18 + lVar20 * 8)) goto LAB_23c0027e4;
          lVar20 = lVar20 + 1;
        } while (*(longlong *)(lVar16 + 0x10) != lVar20);
      }
      goto LAB_23c002592;
    }
    plVar12 = *(longlong **)PyExc_TypeError_exref;
    uVar22 = PyUnicode_FromString
                       ("catching classes that do not inherit from BaseException is not allowed");
    plVar13 = *(longlong **)(param_1 + 0x60);
    plVar15 = *(longlong **)(param_1 + 0x68);
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar12;
    *plVar12 = *plVar12 + 1;
    *(undefined8 *)(param_1 + 0x68) = uVar22;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      (**(code **)(plVar13[1] + 0x30))();
    }
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    if ((plVar17 == (longlong *)0x0) || (*plVar17 = *plVar17 + -1, *plVar17 != 0)) {
LAB_23c0027dd:
      pcVar26 = *(code **)(param_1 + 0x138);
    }
    else {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
      pcVar26 = *(code **)(param_1 + 0x138);
    }
LAB_23c0027e4:
    plVar12 = &DAT_23ed6cce0;
    *(longlong *)pcVar26 = *(longlong *)pcVar26 + 1;
    uVar22 = FUN_23a3a0d40(DAT_23ed6cf28);
    plVar13 = _DAT_23ee07688;
    lVar16 = *(longlong *)(param_1 + 0x10);
    pcVar23 = *(code **)(lVar16 + 0xe20);
    if (pcVar23 == (code *)0x0) {
      pcVar23 = (code *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar20 = *(longlong *)(pcVar23 + 0x18);
      *(int *)(lVar16 + 0xebc) = *(int *)(lVar16 + 0xebc) + -1;
      *(longlong *)(lVar16 + 0xe20) = lVar20;
      *(longlong *)pcVar23 = 1;
    }
    local_110 = _PyRuntime_exref;
    *(longlong *)(pcVar23 + 0x20) = 0;
    lVar16 = *(longlong *)(*(longlong *)(*(longlong *)(local_110 + 0x1f8) + 0x10) + 0x2e8);
    lVar20 = *(longlong *)(pcVar23 + -8);
    puVar5 = *(undefined8 **)(lVar16 + 8);
    *puVar5 = pcVar23 + -0x10;
    *(longlong *)(pcVar23 + -0x10) = lVar16;
    *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar5;
    *(code **)(lVar16 + 8) = pcVar23 + -0x10;
    plVar15 = DAT_23ed6a4c0;
    *plVar13 = *plVar13 + 1;
    *(longlong **)(pcVar23 + 0x18) = plVar13;
    uVar9 = DAT_23ed6cd28;
    if (plVar15 == (longlong *)0x0) {
      plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar15 != (longlong *)0x0) {
        *plVar15 = *plVar15 + 1;
        DAT_23ed6a4c0 = plVar15;
        goto LAB_23c0028aa;
      }
      PyErr_PrintEx(0);
      iVar11 = (int)plVar15;
      Py_Exit(1);
      local_108 = pcVar23;
LAB_23c0039a0:
      if (iVar11 == 0) goto LAB_23c002c77;
      goto LAB_23c002c7f;
    }
LAB_23c0028aa:
    uStack_e0 = uVar9;
    local_e8 = pcVar26;
    lVar16 = FUN_23e94ed00(param_1,plVar15,&local_e8);
    if (lVar16 == 0) {
      local_108 = *(code **)(param_1 + 0x68);
      plVar12 = *(longlong **)(param_1 + 0x60);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
      if (*(longlong *)pcVar23 == 0) {
        (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
      }
    }
    else {
      *(longlong *)(pcVar23 + 0x20) = lVar16;
      plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar23);
      *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
      if (*(longlong *)pcVar23 == 0) {
        (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
      }
      if (plVar12 != (longlong *)0x0) {
        *(undefined4 *)(plVar6 + 5) = 0x8d;
        plVar13 = (longlong *)FUN_23e914090(param_1,uVar22,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar13 != (longlong *)0x0) {
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          pcVar23 = _Py_FalseStruct_exref;
          *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
          *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
          if (*(longlong *)pcVar26 == 0) {
            (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
          }
          plVar12 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = local_118;
          if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
            (**(code **)(plVar12[1] + 0x30))();
          }
          lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar12 = *(longlong **)(lVar16 + 0x28);
          plVar6 = (longlong *)plVar12[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar16 + 0x30);
          *(undefined4 *)(plVar12 + 8) = 0xffffffff;
          if (plVar6 != (longlong *)0x0) {
            plVar12[2] = 0;
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              (**(code **)(plVar6[1] + 0x30))();
            }
          }
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          plVar12[0xf] = 0;
          if (plVar14 == (longlong *)0x0) goto LAB_23c0029d9;
          goto LAB_23c0029cf;
        }
      }
      local_108 = *(code **)(param_1 + 0x68);
      plVar12 = *(longlong **)(param_1 + 0x60);
      pcVar24 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
    }
    *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
    if (*(longlong *)pcVar26 == 0) {
      (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
    }
    pcVar26 = *(code **)(param_1 + 0x138);
    *(longlong **)(param_1 + 0x138) = local_118;
    if (pcVar26 != (code *)0x0) {
      *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
      if (*(longlong *)pcVar26 != 0) {
        if (pcVar24 == (code *)0x0) goto LAB_23c003898;
        plVar13 = *(longlong **)(pcVar24 + 0x18);
        goto joined_r0x00023c002ec6;
      }
      iVar11 = 0x8d;
      goto LAB_23c002f55;
    }
    if (pcVar24 == (code *)0x0) {
LAB_23c003898:
      iVar11 = 0x8d;
      goto LAB_23c002c8b;
    }
    plVar13 = *(longlong **)(pcVar24 + 0x18);
joined_r0x00023c002ec6:
    pcVar23 = pcVar24;
    if (plVar13 == plVar6) goto LAB_23c002d20;
    iVar11 = 0x8d;
LAB_23c002f95:
    pcVar23 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar21 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar21;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar23 + 0x18) = plVar6;
    *plVar6 = *plVar6 + 1;
    *(int *)(pcVar23 + 0x24) = iVar11;
    lVar16 = *(longlong *)(local_110 + 0x1f8);
    *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
    lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
    lVar20 = *(longlong *)(pcVar23 + -8);
    puVar5 = *(undefined8 **)(lVar16 + 8);
    *puVar5 = pcVar23 + -0x10;
    *(longlong *)(pcVar23 + -0x10) = lVar16;
    *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar5;
    lVar20 = *(longlong *)pcVar24;
    *(code **)(lVar16 + 8) = pcVar23 + -0x10;
    *(code **)(pcVar23 + 0x10) = pcVar24;
    if (lVar20 == 0) {
      (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
    }
  }
  else {
    lVar16 = *(longlong *)(pcVar24 + 0x10);
    if (0 < lVar16) {
      lVar20 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar24 + lVar20 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar24 + lVar20 * 8 + 0x18) + 0xab) & 0x40) == 0)) {
          plVar12 = *(longlong **)PyExc_TypeError_exref;
          uVar22 = PyUnicode_FromString
                             (
                             "catching classes that do not inherit from BaseException is not allowed"
                             );
          plVar13 = *(longlong **)(param_1 + 0x60);
          plVar15 = *(longlong **)(param_1 + 0x68);
          plVar17 = *(longlong **)(param_1 + 0x70);
          *(longlong **)(param_1 + 0x60) = plVar12;
          *plVar12 = *plVar12 + 1;
          *(undefined8 *)(param_1 + 0x68) = uVar22;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
            (**(code **)(plVar13[1] + 0x30))();
          }
          if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if ((plVar17 == (longlong *)0x0) || (*plVar17 = *plVar17 + -1, *plVar17 != 0))
          goto LAB_23c0027dd;
          (**(code **)(plVar17[1] + 0x30))(plVar17);
          pcVar26 = *(code **)(param_1 + 0x138);
          goto LAB_23c0027e4;
        }
        lVar20 = lVar20 + 1;
      } while (lVar16 != lVar20);
      lVar20 = 0;
      do {
        iVar11 = FUN_23a35ebd0(param_1,pcVar21,*(undefined8 *)(pcVar24 + lVar20 * 8 + 0x18));
        if (iVar11 != 0) goto LAB_23c0027dd;
        lVar20 = lVar20 + 1;
      } while (lVar16 != lVar20);
      pcVar26 = *(code **)(param_1 + 0x138);
    }
LAB_23c002592:
    if ((pcVar26 == pcVar23) || (pcVar26 == (code *)0x0)) {
      plVar12 = *(longlong **)PyExc_RuntimeError_exref;
      local_108 = (code *)PyUnicode_FromString("No active exception to reraise");
      pcVar26 = *(code **)(param_1 + 0x138);
      *plVar12 = *plVar12 + 1;
      *(longlong **)(param_1 + 0x138) = local_118;
      if ((pcVar26 != (code *)0x0) &&
         (*(longlong *)pcVar26 = *(longlong *)pcVar26 + -1, *(longlong *)pcVar26 == 0)) {
        pcVar24 = (code *)0x0;
        iVar11 = 0x88;
LAB_23c002f55:
        (**(code **)(*(longlong *)(pcVar26 + 8) + 0x30))(pcVar26);
        if (pcVar24 == (code *)0x0) goto LAB_23c0039a0;
LAB_23c002f71:
        pcVar23 = pcVar24;
        if (plVar6 == *(longlong **)(pcVar24 + 0x18)) goto LAB_23c002d20;
        if (iVar11 == 0) goto LAB_23c002f86;
        local_110 = _PyRuntime_exref;
        goto LAB_23c002f95;
      }
      local_110 = _PyRuntime_exref;
      iVar11 = 0x88;
    }
    else {
      plVar12 = *(longlong **)(pcVar26 + 8);
      pcVar24 = *(code **)(pcVar26 + 0x28);
      *(longlong *)pcVar26 = *(longlong *)pcVar26 + 1;
      *plVar12 = *plVar12 + 1;
      local_108 = pcVar26;
      if (pcVar24 != (code *)0x0) {
        *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
        if (plVar6 == *(longlong **)(pcVar24 + 0x18)) {
          *(undefined4 *)(plVar6 + 5) = *(undefined4 *)(pcVar24 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = local_118;
        *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
        if (*(longlong *)pcVar26 == 0) {
          (*(code *)plVar12[6])(pcVar26);
          iVar11 = 0;
          goto LAB_23c002f71;
        }
        pcVar23 = pcVar24;
        if (*(longlong **)(pcVar24 + 0x18) == plVar6) goto LAB_23c002d20;
LAB_23c002f86:
        iVar11 = (int)plVar6[5];
        local_110 = _PyRuntime_exref;
        goto LAB_23c002f95;
      }
      *(longlong **)(param_1 + 0x138) = local_118;
      *(longlong *)pcVar26 = *(longlong *)pcVar26 + -1;
      if (*(longlong *)pcVar26 == 0) {
        iVar11 = 0;
        goto LAB_23c002f55;
      }
LAB_23c002c77:
      iVar11 = (int)plVar6[5];
LAB_23c002c7f:
      local_110 = _PyRuntime_exref;
    }
LAB_23c002c8b:
    pcVar23 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar24 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar24;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong *)(pcVar23 + 0x10) = 0;
    *(longlong **)(pcVar23 + 0x18) = plVar6;
    *plVar6 = *plVar6 + 1;
    *(int *)(pcVar23 + 0x24) = iVar11;
    lVar16 = *(longlong *)(local_110 + 0x1f8);
    *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
    lVar16 = *(longlong *)(*(longlong *)(lVar16 + 0x10) + 0x2e8);
    lVar20 = *(longlong *)(pcVar23 + -8);
    puVar5 = *(undefined8 **)(lVar16 + 8);
    *puVar5 = pcVar23 + -0x10;
    *(longlong *)(pcVar23 + -0x10) = lVar16;
    *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar5;
    *(code **)(lVar16 + 8) = pcVar23 + -0x10;
  }
LAB_23c002d20:
  FUN_23e8bba40(plVar6,&DAT_23ec43a64,plVar3,plVar4,plVar14,0);
  if (_DAT_23ee0b5f0 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23ee0b5f0 = (longlong *)0x0;
  }
  lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar16 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar16 + 0x30);
  plVar13 = (longlong *)plVar6[2];
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  FUN_23a33aa70(param_1,plVar12,local_108,pcVar23);
  return (code *)0x0;
}
