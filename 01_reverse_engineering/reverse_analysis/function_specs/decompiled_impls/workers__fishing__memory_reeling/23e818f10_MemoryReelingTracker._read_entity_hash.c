/* ===== 23e818f10 workers.fishing.memory_reeling:MemoryReelingTracker._read_entity_hash ===== */
/* ghidra_name=FUN_23e818f10 entry=23e818f10 size=15692 */

code * FUN_23e818f10(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  char cVar9;
  int iVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong *plVar21;
  undefined8 uVar22;
  code *pcVar23;
  longlong *plVar24;
  code *pcVar25;
  undefined4 uVar26;
  code *local_138;
  longlong *local_110;
  longlong *local_108;
  longlong *local_100;
  longlong *local_f8;
  longlong *local_f0;
  longlong *local_e8;
  longlong *local_e0;
  longlong *local_d8;
  longlong *local_d0;
  longlong *local_c8;
  undefined1 local_98 [16];
  longlong *local_88 [2];
  longlong *local_78;
  longlong *plStack_70;
  longlong *local_68;
  longlong *local_60;
  
  plVar15 = DAT_23ed6a4e0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar15 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    plVar11 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar11;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar23 = _PyRuntime_exref;
  plVar11 = DAT_23eede800;
  plVar15[2] = 0;
  lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar23 + 0x1f8) + 0x10) + 0x2e8);
  lVar4 = plVar15[-1];
  puVar5 = *(undefined8 **)(lVar12 + 8);
  *puVar5 = plVar15 + -2;
  plVar15[-2] = lVar12;
  plVar15[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
  *(longlong **)(lVar12 + 8) = plVar15 + -2;
  local_88[0] = (longlong *)0x0;
  local_98._0_8_ = (code *)0x0;
  local_98._8_8_ = 0;
  if (plVar11 == (longlong *)0x0) {
LAB_23e819006:
    plVar11 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede9f0,DAT_23eedd0f8,0x90);
    DAT_23eede800 = plVar11;
  }
  else {
    lVar12 = *plVar11;
    if (1 < lVar12) {
      *plVar11 = lVar12 + -1;
      goto LAB_23e819006;
    }
    if (plVar11[2] != 0) {
      *plVar11 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e819006;
    }
  }
  lVar12 = *(longlong *)(param_1 + 0x38);
  lVar4 = *(longlong *)(lVar12 + 8);
  plVar11[0xf] = lVar4;
  *(longlong **)(lVar12 + 8) = plVar11 + 9;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar11[0xe] != 0)))) {
    plVar14 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar11[0xe] + 0x10) = plVar14;
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
  }
  *plVar11 = *plVar11 + 1;
  *(undefined4 *)(plVar11 + 8) = 0;
  lVar12 = PyNumber_Long(plVar2);
  if (lVar12 == 0) {
    local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    local_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    lVar4 = *(longlong *)(param_1 + 0x10);
    plVar14 = *(longlong **)(lVar4 + 0xe20);
    if (plVar14 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar6 = plVar14[3];
      *(int *)(lVar4 + 0xebc) = *(int *)(lVar4 + 0xebc) + -1;
      *(longlong *)(lVar4 + 0xe20) = lVar6;
      *plVar14 = 1;
    }
    pcVar23 = _PyRuntime_exref;
    plVar14[4] = 0;
    lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar23 + 0x1f8) + 0x10) + 0x2e8);
    lVar6 = plVar14[-1];
    puVar5 = *(undefined8 **)(lVar4 + 8);
    *puVar5 = plVar14 + -2;
    plVar14[-2] = lVar4;
    plVar14[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar4 + 8) = plVar14 + -2;
    plVar14[3] = lVar12;
    lVar12 = PyNumber_Long(plVar3);
    uVar22 = DAT_23eedd1b8;
    if (lVar12 != 0) {
      plVar14[4] = lVar12;
      local_138 = (code *)FUN_23e8bc2f0(plVar1,uVar22);
      if (local_138 == (code *)0x0) {
LAB_23e819e00:
        local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        plVar13 = *(longlong **)(param_1 + 0x70);
        pcVar23 = (code *)0x0;
        plVar21 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar26 = 0x1dd;
        local_100 = (longlong *)0x0;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar17 = DAT_23ed6a4f8;
        goto joined_r0x00023e819693;
      }
      plVar13 = (longlong *)FUN_23e8bc2f0(local_138,DAT_23ed6ce40);
      lVar12 = *(longlong *)local_138;
      *(longlong *)local_138 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(*(longlong *)(local_138 + 8) + 0x30))(local_138);
      }
      if (plVar13 == (longlong *)0x0) {
        local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        plVar13 = *(longlong **)(param_1 + 0x70);
        pcVar23 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_100 = (longlong *)0x0;
        uVar26 = 0x1dd;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        local_138 = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar21 = (longlong *)0x0;
        plVar17 = DAT_23ed6a4f8;
        goto joined_r0x00023e819693;
      }
      *(undefined4 *)(plVar11 + 5) = 0x1dd;
      local_138 = (code *)FUN_23e914090(param_1,plVar13,plVar14);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      pcVar25 = _Py_NoneStruct_exref;
      if (local_138 == (code *)0x0) goto LAB_23e819e00;
      if (local_138 != _Py_NoneStruct_exref) {
        lVar12 = *(longlong *)(param_1 + 0x38);
        *(longlong *)local_138 = *(longlong *)local_138 + 1;
        lVar4 = *(longlong *)(lVar12 + 8);
        plVar11 = *(longlong **)(lVar4 + 0x28);
        plVar13 = (longlong *)plVar11[2];
        *(undefined8 *)(lVar12 + 8) = *(undefined8 *)(lVar4 + 0x30);
        *(undefined4 *)(plVar11 + 8) = 0xffffffff;
        if (plVar13 != (longlong *)0x0) {
          plVar11[2] = 0;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))();
          }
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        local_100 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar17 = (longlong *)0x0;
        local_e0 = (longlong *)0x0;
        plVar21 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_110 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        plVar11[0xf] = 0;
        pcVar23 = local_138;
        pcVar25 = (code *)0x0;
LAB_23e8192f5:
        lVar12 = *plVar14;
        *plVar14 = lVar12 + -1;
        if (lVar12 + -1 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        lVar12 = *(longlong *)local_138;
        *(longlong *)local_138 = lVar12 + -1;
        if (lVar12 + -1 == 0) {
          (**(code **)(*(longlong *)(local_138 + 8) + 0x30))(local_138);
        }
        if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
          (**(code **)(plVar21[1] + 0x30))(plVar21);
        }
        if ((local_108 != (longlong *)0x0) &&
           (lVar12 = *local_108, *local_108 = lVar12 + -1, lVar12 + -1 == 0)) {
          (**(code **)(local_108[1] + 0x30))(local_108);
        }
        if ((local_110 != (longlong *)0x0) &&
           (lVar12 = *local_110, *local_110 = lVar12 + -1, lVar12 + -1 == 0)) {
          (**(code **)(local_110[1] + 0x30))(local_110);
        }
        if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if ((local_f8 != (longlong *)0x0) &&
           (lVar12 = *local_f8, *local_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
          (**(code **)(local_f8[1] + 0x30))(local_f8);
        }
        if ((local_f0 != (longlong *)0x0) &&
           (lVar12 = *local_f0, *local_f0 = lVar12 + -1, lVar12 + -1 == 0)) {
          (**(code **)(local_f0[1] + 0x30))(local_f0);
        }
        if ((local_e8 != (longlong *)0x0) &&
           (lVar12 = *local_e8, *local_e8 = lVar12 + -1, lVar12 + -1 == 0)) {
          (**(code **)(local_e8[1] + 0x30))(local_e8);
        }
        if ((local_d8 != (longlong *)0x0) &&
           (lVar12 = *local_d8, *local_d8 = lVar12 + -1, lVar12 + -1 == 0)) {
          (**(code **)(local_d8[1] + 0x30))(local_d8);
        }
        if ((local_e0 != (longlong *)0x0) &&
           (lVar12 = *local_e0, *local_e0 = lVar12 + -1, lVar12 + -1 == 0)) {
          (**(code **)(local_e0[1] + 0x30))(local_e0);
        }
        if ((local_100 != (longlong *)0x0) &&
           (lVar12 = *local_100, *local_100 = lVar12 + -1, lVar12 + -1 == 0)) {
          (**(code **)(local_100[1] + 0x30))(local_100);
        }
        if ((pcVar25 != (code *)0x0) &&
           (*(longlong *)pcVar25 = *(longlong *)pcVar25 + -1, *(longlong *)pcVar25 == 0)) {
          (**(code **)(*(longlong *)(pcVar25 + 8) + 0x30))(pcVar25);
        }
        lVar12 = *plVar1;
        *plVar1 = lVar12 + -1;
        if (lVar12 + -1 == 0) {
          (**(code **)(plVar1[1] + 0x30))(plVar1);
        }
        lVar12 = *plVar2;
        *plVar2 = lVar12 + -1;
        if (lVar12 + -1 == 0) {
          (**(code **)(plVar2[1] + 0x30))(plVar2);
        }
        lVar12 = *plVar3;
        *plVar3 = lVar12 + -1;
        if (lVar12 + -1 != 0) {
          return pcVar23;
        }
        (**(code **)(plVar3[1] + 0x30))(plVar3);
        return pcVar23;
      }
      lVar12 = *(longlong *)(param_1 + 0x10);
      if (*(int *)(lVar12 + 0x1188) == 0) {
        plVar21 = (longlong *)FUN_23a33a530(PyList_Type_exref);
      }
      else {
        iVar10 = *(int *)(lVar12 + 0x1188) + -1;
        *(int *)(lVar12 + 0x1188) = iVar10;
        plVar21 = *(longlong **)(lVar12 + 0xf08 + (longlong)iVar10 * 8);
        *plVar21 = 1;
      }
      pcVar23 = _PyRuntime_exref;
      plVar21[2] = 0;
      plVar21[4] = 0;
      lVar12 = *(longlong *)(pcVar23 + 0x1f8);
      plVar21[3] = 0;
      lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
      lVar4 = plVar21[-1];
      puVar5 = *(undefined8 **)(lVar12 + 8);
      *puVar5 = plVar21 + -2;
      plVar21[-2] = lVar12;
      plVar21[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
      *(longlong **)(lVar12 + 8) = plVar21 + -2;
      lVar4 = DAT_23eedd0f0;
      *plVar2 = *plVar2 + 1;
      lVar12 = *(longlong *)(lVar4 + 0x20);
      local_108 = plVar2;
      if (*(char *)(lVar12 + 10) == '\0') {
        plVar13 = (longlong *)FUN_23a37a020(lVar4,DAT_23eedd670);
        if (plVar13 == (longlong *)0x0) goto LAB_23e81a700;
        lVar12 = *plVar13;
LAB_23e81a6f4:
        if (lVar12 == 0) goto LAB_23e81a700;
      }
      else {
        iVar10 = *(int *)(lVar12 + 0xc);
        if (*(int *)(lVar12 + 0xc) == 0) {
          *(int *)(lVar12 + 0xc) = DAT_23ec155d8;
          iVar10 = DAT_23ec155d8;
          DAT_23ec155d8 = DAT_23ec155d8 + 1;
        }
        if (DAT_23ec15584 != iVar10) {
          DAT_23ec15584 = iVar10;
          DAT_23eede7d0 = FUN_23e8cbd60(lVar12,DAT_23eedd670,*(undefined8 *)(DAT_23eedd670 + 0x18));
        }
        if (-1 < DAT_23eede7d0) {
          lVar4 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
          if (*(longlong *)(lVar4 + 8 + DAT_23eede7d0 * 0x10) != 0) goto LAB_23e81a083;
          DAT_23eede7d0 = FUN_23e8cbd60(lVar12,DAT_23eedd670,*(undefined8 *)(DAT_23eedd670 + 0x18));
          if (-1 < DAT_23eede7d0) {
            lVar12 = *(longlong *)(lVar4 + 8 + DAT_23eede7d0 * 0x10);
            goto LAB_23e81a6f4;
          }
        }
LAB_23e81a700:
        plVar13 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedd670);
        if ((plVar13 == (longlong *)0x0) || (*plVar13 == 0)) {
          pcVar23 = (code *)0x0;
          FUN_23e915740(param_1,local_98,DAT_23eedd670);
          local_100 = (longlong *)0x0;
          uVar26 = 0x1e3;
          local_e0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          local_e8 = (longlong *)0x0;
          local_f0 = (longlong *)0x0;
          local_f8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_d0 = (longlong *)0x0;
          local_110 = (longlong *)0x0;
          plVar17 = DAT_23ed6a4f8;
          local_138 = pcVar25;
          plVar13 = local_88[0];
          goto joined_r0x00023e819693;
        }
      }
LAB_23e81a083:
      *(undefined4 *)(plVar11 + 5) = 0x1e3;
      local_110 = (longlong *)FUN_23e91a870(param_1);
      if (local_110 == (longlong *)0x0) {
        plVar13 = *(longlong **)(param_1 + 0x70);
        pcVar23 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        local_100 = (longlong *)0x0;
        uVar26 = 0x1e3;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar17 = DAT_23ed6a4f8;
        local_138 = pcVar25;
      }
      else {
        local_100 = (longlong *)0x0;
        local_e0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        local_e8 = (longlong *)0x0;
        local_f0 = (longlong *)0x0;
        local_f8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_d0 = (longlong *)0x0;
        do {
          lVar12 = FUN_23e8dcc30();
          if (lVar12 == 0) {
            FUN_23e915740(param_1,local_98,DAT_23eedd200);
LAB_23e81b222:
            pcVar23 = (code *)0x0;
            uVar26 = 0x1e5;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            plVar13 = local_88[0];
            goto joined_r0x00023e819693;
          }
          plVar13 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23eedd678);
          if (plVar13 == (longlong *)0x0) {
LAB_23e81b59f:
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_88[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e81b222;
          }
          if (plVar1 == (longlong *)0x0) {
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            local_98._8_8_ =
                 PyUnicode_FromFormat
                           ("cannot access local variable \'%U\' where it is not associated with a value"
                            ,DAT_23eedd4b0);
            local_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
            *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + 1;
            local_88[0] = (longlong *)0x0;
            if ((code *)local_98._0_8_ != pcVar25) {
              FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
            }
            FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_98._8_8_);
            goto LAB_23e81b222;
          }
          plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd138);
          if (plVar16 == (longlong *)0x0) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_88[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            goto LAB_23e81b222;
          }
          if ((DAT_23ed8fb50 == 0) &&
             (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
LAB_23e81aa3b:
            FUN_23e9364c0("%s : %s\n","IMPORT_HARD_CTYPES",
                          "\"Unexpected failure of hard import of \'ctypes\'\"");
                    /* WARNING: Subroutine does not return */
            abort();
          }
          plVar17 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedd358);
          if (plVar17 == (longlong *)0x0) {
LAB_23e81b538:
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_88[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            goto LAB_23e81b222;
          }
          *(undefined4 *)(plVar11 + 5) = 0x1e5;
          plVar18 = (longlong *)FUN_23e914090(param_1,plVar17,local_108);
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          if (plVar18 == (longlong *)0x0) goto LAB_23e81b538;
          if ((DAT_23ed8fb50 == 0) &&
             (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
            DAT_23ed8fb50 = 0;
            goto LAB_23e81aa3b;
          }
          plVar17 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedd360);
          if (plVar17 == (longlong *)0x0) {
LAB_23e81b5da:
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_88[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            *plVar18 = *plVar18 + -1;
            if (*plVar18 == 0) {
              (**(code **)(plVar18[1] + 0x30))(plVar18);
            }
            goto LAB_23e81b222;
          }
          *(undefined4 *)(plVar11 + 5) = 0x1e5;
          plVar19 = (longlong *)FUN_23e914090(param_1,plVar17,local_110);
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          if (plVar19 == (longlong *)0x0) goto LAB_23e81b5da;
          if ((DAT_23ed8fb50 == 0) &&
             (DAT_23ed8fb50 = PyImport_ImportModule("ctypes"), DAT_23ed8fb50 == 0)) {
            DAT_23ed8fb50 = 0;
            goto LAB_23e81aa3b;
          }
          plVar17 = (longlong *)FUN_23e8bc2f0(DAT_23ed8fb50,DAT_23eedd440);
          if (plVar17 == (longlong *)0x0) {
LAB_23e81b6c2:
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_88[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            *plVar18 = *plVar18 + -1;
            if (*plVar18 == 0) {
              (**(code **)(plVar18[1] + 0x30))(plVar18);
            }
            *plVar19 = *plVar19 + -1;
            if (*plVar19 == 0) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
            }
            goto LAB_23e81b222;
          }
          *(undefined4 *)(plVar11 + 5) = 0x1e5;
          plVar20 = (longlong *)FUN_23e914090(param_1,plVar17,local_110);
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          if (plVar20 == (longlong *)0x0) goto LAB_23e81b6c2;
          *(undefined4 *)(plVar11 + 5) = 0x1e5;
          local_78 = plVar16;
          plStack_70 = plVar18;
          local_68 = plVar19;
          local_60 = plVar20;
          plVar17 = (longlong *)FUN_23e9583d0(param_1,plVar13,&local_78);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          *plVar19 = *plVar19 + -1;
          if (*plVar19 == 0) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
          }
          *plVar20 = *plVar20 + -1;
          if (*plVar20 == 0) {
            (**(code **)(plVar20[1] + 0x30))(plVar20);
          }
          if (plVar17 == (longlong *)0x0) goto LAB_23e81b59f;
          if ((local_d0 != (longlong *)0x0) &&
             (lVar12 = *local_d0, *local_d0 = lVar12 + -1, lVar12 + -1 == 0)) {
            (**(code **)(local_d0[1] + 0x30))(local_d0);
          }
          iVar10 = FUN_23a35f020(plVar17);
          local_d0 = plVar17;
          if (iVar10 == -1) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            pcVar23 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar26 = 0x1e6;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            goto joined_r0x00023e819693;
          }
          plVar13 = local_c8;
          if (iVar10 == 0) {
LAB_23e81b7a8:
            pcVar23 = (code *)PySequence_Tuple(plVar21);
            local_c8 = plVar13;
            if (pcVar23 == (code *)0x0) {
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              plVar13 = *(longlong **)(param_1 + 0x70);
              uVar26 = 0x201;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar17 = DAT_23ed6a4f8;
              local_138 = pcVar25;
              goto joined_r0x00023e819693;
            }
            plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd1b8);
            if (plVar16 == (longlong *)0x0) {
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              plVar13 = *(longlong **)(param_1 + 0x70);
              uVar26 = 0x202;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar17 = DAT_23ed6a4f8;
              local_138 = pcVar25;
              goto joined_r0x00023e819693;
            }
            cVar9 = FUN_23a39bc50(param_1,plVar16,plVar14,pcVar23);
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            if (cVar9 == '\0') {
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              plVar13 = *(longlong **)(param_1 + 0x70);
              uVar26 = 0x202;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar17 = DAT_23ed6a4f8;
              local_138 = pcVar25;
              goto joined_r0x00023e819693;
            }
            lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar11 = *(longlong **)(lVar12 + 0x28);
            plVar16 = (longlong *)plVar11[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
            *(undefined4 *)(plVar11 + 8) = 0xffffffff;
            if (plVar16 != (longlong *)0x0) {
              plVar11[2] = 0;
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))();
              }
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            plVar11[0xf] = 0;
            *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
            pcVar25 = pcVar23;
            goto LAB_23e8192f5;
          }
          plVar13 = (longlong *)FUN_23e8bc2f0(local_110,DAT_23eedd690);
          if (plVar13 == (longlong *)0x0) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            pcVar23 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar26 = 0x1e8;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            goto joined_r0x00023e819693;
          }
          if ((local_c8 != (longlong *)0x0) &&
             (lVar12 = *local_c8, *local_c8 = lVar12 + -1, lVar12 + -1 == 0)) {
            (**(code **)(local_c8[1] + 0x30))(local_c8);
          }
          iVar10 = FUN_23e97a530(plVar13,DAT_23ed6ccf0);
          local_c8 = plVar13;
          if (iVar10 == -1) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            pcVar23 = (code *)0x0;
            uVar26 = 0x1e9;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            goto joined_r0x00023e819693;
          }
          if (iVar10 == 1) goto LAB_23e81b7a8;
          lVar12 = FUN_23e8bc2f0(local_110,DAT_23eedd698);
          if (lVar12 == 0) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar26 = 0x1eb;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar23 = (code *)0x0;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            goto joined_r0x00023e819693;
          }
          plVar16 = (longlong *)plVar15[2];
          plVar15[2] = lVar12;
          if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
            (**(code **)(plVar16[1] + 0x30))();
            lVar12 = plVar15[2];
          }
          iVar10 = FUN_23e97d0c0(lVar12,plVar3);
          if (iVar10 == -1) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            pcVar23 = (code *)0x0;
            uVar26 = 0x1ec;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            goto joined_r0x00023e819693;
          }
          if (iVar10 == 1) goto LAB_23e81b7a8;
          plVar16 = (longlong *)FUN_23e8bc2f0(local_110,DAT_23eedd6a0);
          if (plVar16 == (longlong *)0x0) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar26 = 0x1ee;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar23 = (code *)0x0;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            goto joined_r0x00023e819693;
          }
          lVar12 = *(longlong *)(DAT_23eedd0f0 + 0x20);
          if (*(char *)(lVar12 + 10) != '\0') {
            iVar10 = *(int *)(lVar12 + 0xc);
            if (*(int *)(lVar12 + 0xc) == 0) {
              *(int *)(lVar12 + 0xc) = DAT_23ec155d8;
              iVar10 = DAT_23ec155d8;
              DAT_23ec155d8 = DAT_23ec155d8 + 1;
            }
            if (DAT_23ec15588 != iVar10) {
              DAT_23ec15588 = iVar10;
              DAT_23eede7d8 =
                   FUN_23e8cbd60(lVar12,DAT_23eedd6a8,*(undefined8 *)(DAT_23eedd6a8 + 0x18));
            }
            if (-1 < DAT_23eede7d8) {
              lVar4 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
              if (*(longlong *)(lVar4 + 8 + DAT_23eede7d8 * 0x10) != 0) goto LAB_23e81a4f3;
              DAT_23eede7d8 =
                   FUN_23e8cbd60(lVar12,DAT_23eedd6a8,*(undefined8 *)(DAT_23eedd6a8 + 0x18));
              if (-1 < DAT_23eede7d8) {
                lVar12 = *(longlong *)(lVar4 + 8 + DAT_23eede7d8 * 0x10);
                goto LAB_23e81a804;
              }
            }
LAB_23e81a810:
            plVar18 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedd6a8);
            if ((plVar18 != (longlong *)0x0) && (*plVar18 != 0)) goto LAB_23e81a4f3;
            FUN_23e915740(param_1,local_98,DAT_23eedd6a8);
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
LAB_23e81a88c:
            uVar26 = 0x1ee;
            pcVar23 = (code *)0x0;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            plVar13 = local_88[0];
            goto joined_r0x00023e819693;
          }
          plVar18 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,DAT_23eedd6a8);
          if (plVar18 == (longlong *)0x0) goto LAB_23e81a810;
          lVar12 = *plVar18;
LAB_23e81a804:
          if (lVar12 == 0) goto LAB_23e81a810;
LAB_23e81a4f3:
          iVar10 = FUN_23e912620(plVar16);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (iVar10 == -1) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_88[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e81a88c;
          }
          if (iVar10 != 1) goto LAB_23e81a520;
          plVar16 = (longlong *)FUN_23e8bc2f0(local_110,DAT_23eedd6b0);
          if (plVar16 == (longlong *)0x0) {
LAB_23e81c01b:
            local_88[0] = *(longlong **)(param_1 + 0x70);
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e81c05f:
            pcVar23 = (code *)0x0;
            uVar26 = 0x1ef;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            plVar13 = local_88[0];
            goto joined_r0x00023e819693;
          }
          lVar12 = *(longlong *)(DAT_23eedd0f0 + 0x20);
          if (*(char *)(lVar12 + 10) != '\0') {
            iVar10 = *(int *)(lVar12 + 0xc);
            if (*(int *)(lVar12 + 0xc) == 0) {
              *(int *)(lVar12 + 0xc) = DAT_23ec155d8;
              iVar10 = DAT_23ec155d8;
              DAT_23ec155d8 = DAT_23ec155d8 + 1;
            }
            if (DAT_23ec1558c != iVar10) {
              DAT_23ec1558c = iVar10;
              DAT_23eede7e0 =
                   FUN_23e8cbd60(lVar12,DAT_23eedd6b8,*(undefined8 *)(DAT_23eedd6b8 + 0x18));
            }
            if (-1 < DAT_23eede7e0) {
              lVar4 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
              if (*(longlong *)(lVar4 + 8 + DAT_23eede7e0 * 0x10) != 0) goto LAB_23e81ab6d;
              DAT_23eede7e0 =
                   FUN_23e8cbd60(lVar12,DAT_23eedd6b8,*(undefined8 *)(DAT_23eedd6b8 + 0x18));
              if (-1 < DAT_23eede7e0) {
                lVar12 = *(longlong *)(lVar4 + 8 + DAT_23eede7e0 * 0x10);
                goto LAB_23e81b33c;
              }
            }
LAB_23e81b345:
            plVar18 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedd6b8);
            if ((plVar18 != (longlong *)0x0) && (*plVar18 != 0)) goto LAB_23e81ab6d;
            FUN_23e915740(param_1,local_98,DAT_23eedd6b8);
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
LAB_23e81b3ed:
            uVar26 = 0x1ef;
            pcVar23 = (code *)0x0;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            plVar13 = local_88[0];
            goto joined_r0x00023e819693;
          }
          plVar18 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,DAT_23eedd6b8);
          if (plVar18 == (longlong *)0x0) goto LAB_23e81b345;
          lVar12 = *plVar18;
LAB_23e81b33c:
          if (lVar12 == 0) goto LAB_23e81b345;
LAB_23e81ab6d:
          lVar12 = *(longlong *)(DAT_23eedd0f0 + 0x20);
          if (*(char *)(lVar12 + 10) == '\0') {
            plVar18 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,DAT_23eedd6c0);
            if (plVar18 == (longlong *)0x0) goto LAB_23e81b45c;
            lVar12 = *plVar18;
LAB_23e81b453:
            if (lVar12 == 0) goto LAB_23e81b45c;
          }
          else {
            iVar10 = *(int *)(lVar12 + 0xc);
            if (*(int *)(lVar12 + 0xc) == 0) {
              *(int *)(lVar12 + 0xc) = DAT_23ec155d8;
              iVar10 = DAT_23ec155d8;
              DAT_23ec155d8 = DAT_23ec155d8 + 1;
            }
            if (DAT_23ec15590 != iVar10) {
              DAT_23ec15590 = iVar10;
              DAT_23eede7e8 =
                   FUN_23e8cbd60(lVar12,DAT_23eedd6c0,*(undefined8 *)(DAT_23eedd6c0 + 0x18));
            }
            if (-1 < DAT_23eede7e8) {
              lVar4 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
              if (*(longlong *)(lVar4 + 8 + DAT_23eede7e8 * 0x10) != 0) goto LAB_23e81abda;
              DAT_23eede7e8 =
                   FUN_23e8cbd60(lVar12,DAT_23eedd6c0,*(undefined8 *)(DAT_23eedd6c0 + 0x18));
              if (-1 < DAT_23eede7e8) {
                lVar12 = *(longlong *)(lVar4 + 8 + DAT_23eede7e8 * 0x10);
                goto LAB_23e81b453;
              }
            }
LAB_23e81b45c:
            plVar18 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedd6c0);
            if ((plVar18 == (longlong *)0x0) || (*plVar18 == 0)) {
              FUN_23e915740(param_1,local_98,DAT_23eedd6c0);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                FUN_23a334bc0(plVar16);
              }
              goto LAB_23e81b3ed;
            }
          }
LAB_23e81abda:
          plVar18 = (longlong *)FUN_23e8c1360();
          if (plVar18 == (longlong *)0x0) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_88[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              FUN_23a334bc0(plVar16);
            }
            goto LAB_23e81c05f;
          }
          plVar19 = (longlong *)FUN_23e8c0ec0(plVar16,plVar18);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          if (plVar19 == (longlong *)0x0) goto LAB_23e81c01b;
          iVar10 = FUN_23a35f020(plVar19);
          *plVar19 = *plVar19 + -1;
          if (*plVar19 == 0) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
          }
          if (iVar10 == -1) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_88[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e81b3ed;
          }
          if (iVar10 != 0) goto LAB_23e81a520;
          lVar12 = *(longlong *)(DAT_23eedd0f0 + 0x20);
          if (*(char *)(lVar12 + 10) != '\0') {
            iVar10 = *(int *)(lVar12 + 0xc);
            if (*(int *)(lVar12 + 0xc) == 0) {
              *(int *)(lVar12 + 0xc) = DAT_23ec155d8;
              iVar10 = DAT_23ec155d8;
              DAT_23ec155d8 = DAT_23ec155d8 + 1;
            }
            if (DAT_23ec15594 != iVar10) {
              DAT_23ec15594 = iVar10;
              DAT_23eede7f0 =
                   FUN_23e8cbd60(lVar12,DAT_23eedd6c8,*(undefined8 *)(DAT_23eedd6c8 + 0x18));
            }
            if (-1 < DAT_23eede7f0) {
              lVar4 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
              if (*(longlong *)(lVar4 + 8 + DAT_23eede7f0 * 0x10) != 0) goto LAB_23e81acc0;
              DAT_23eede7f0 =
                   FUN_23e8cbd60(lVar12,DAT_23eedd6c8,*(undefined8 *)(DAT_23eedd6c8 + 0x18));
              if (-1 < DAT_23eede7f0) {
                lVar12 = *(longlong *)(lVar4 + 8 + DAT_23eede7f0 * 0x10);
                goto LAB_23e81bd04;
              }
            }
LAB_23e81bd0d:
            plVar16 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedd6c8);
            if ((plVar16 != (longlong *)0x0) && (*plVar16 != 0)) goto LAB_23e81acc0;
            FUN_23e915740(param_1,local_98,DAT_23eedd6c8);
LAB_23e81bd7e:
            uVar26 = 0x1f0;
            pcVar23 = (code *)0x0;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            plVar13 = local_88[0];
            goto joined_r0x00023e819693;
          }
          plVar16 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,DAT_23eedd6c8);
          if (plVar16 == (longlong *)0x0) goto LAB_23e81bd0d;
          lVar12 = *plVar16;
LAB_23e81bd04:
          if (lVar12 == 0) goto LAB_23e81bd0d;
LAB_23e81acc0:
          iVar10 = FUN_23e97b4b0(plVar13);
          if (iVar10 == -1) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            local_88[0] = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e81bd7e;
          }
          if (iVar10 != 1) goto LAB_23e81a520;
          plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedd148);
          if (plVar16 == (longlong *)0x0) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e81c1bb:
            pcVar23 = (code *)0x0;
            uVar26 = 0x1f1;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            goto joined_r0x00023e819693;
          }
          plVar18 = (longlong *)FUN_23ebf7180(plVar16);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          plVar16 = DAT_23ed6a4e0;
          if (plVar18 == (longlong *)0x0) {
LAB_23e81c17f:
            plVar13 = *(longlong **)(param_1 + 0x70);
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e81c1bb;
          }
          if (DAT_23ed6a4e0 == (longlong *)0x0) {
            plVar16 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
          }
          else {
            plVar19 = (longlong *)*DAT_23ed6a4e0;
            *DAT_23ed6a4e0 = 1;
            DAT_23ed6a4e0 = plVar19;
            DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
          }
          pcVar23 = _PyRuntime_exref;
          plVar16[2] = (longlong)plVar18;
          *plVar18 = *plVar18 + 1;
          lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar23 + 0x1f8) + 0x10) + 0x2e8);
          lVar4 = plVar16[-1];
          puVar5 = *(undefined8 **)(lVar12 + 8);
          *puVar5 = plVar16 + -2;
          uVar8 = DAT_23eedd6f0;
          uVar22 = DAT_23eedd0f8;
          plVar16[-2] = lVar12;
          plVar16[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
          *(longlong **)(lVar12 + 8) = plVar16 + -2;
          uVar7 = DAT_23eedd4f0;
          *plVar15 = *plVar15 + 1;
          local_78 = plVar16;
          plStack_70 = plVar15;
          plVar16 = (longlong *)
                    FUN_23e91ecd0(FUN_23e81ccf0,uVar22,uVar7,uVar8,DAT_23eedea30,&local_78,2,0x108);
          *plVar18 = *plVar18 + -1;
          if (*plVar18 == 0) {
            (**(code **)(plVar18[1] + 0x30))(plVar18);
          }
          plVar18 = (longlong *)FUN_23e8bd690(param_1,plVar16);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (plVar18 == (longlong *)0x0) goto LAB_23e81c17f;
          if ((local_f8 != (longlong *)0x0) &&
             (lVar12 = *local_f8, *local_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
            FUN_23a334bc0(local_f8);
          }
          iVar10 = FUN_23a35f020(plVar18);
          local_f8 = plVar18;
          if (iVar10 == 0) {
            uVar22 = FUN_23a3a0d40(DAT_23eedd4c0);
            plVar16 = (longlong *)FUN_23e8c09e0(plVar15[2],plVar13);
            if (plVar16 == (longlong *)0x0) {
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              plVar13 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              *(undefined4 *)(plVar11 + 5) = 499;
              local_78 = plVar16;
              plStack_70 = plVar3;
              plVar18 = (longlong *)FUN_23e94ed00(param_1,uVar22);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                FUN_23a334bc0(plVar16);
              }
              if (plVar18 != (longlong *)0x0) {
                if ((local_f0 != (longlong *)0x0) &&
                   (lVar12 = *local_f0, *local_f0 = lVar12 + -1, lVar12 + -1 == 0)) {
                  FUN_23a334bc0(local_f0);
                }
                plVar16 = (longlong *)FUN_23e8c6640(plVar18,plVar15[2]);
                local_f0 = plVar18;
                if (plVar16 == (longlong *)0x0) {
                  local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  plVar13 = *(longlong **)(param_1 + 0x70);
                  uVar26 = 500;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcVar23 = (code *)0x0;
                  plVar17 = DAT_23ed6a4f8;
                  local_138 = pcVar25;
                }
                else {
                  iVar10 = FUN_23e97d380(plVar16,DAT_23eedd578);
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0();
                  }
                  if (iVar10 == -1) {
                    local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    plVar13 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar26 = 500;
                    pcVar23 = (code *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar17 = DAT_23ed6a4f8;
                    local_138 = pcVar25;
                  }
                  else {
                    if (iVar10 != 1) goto LAB_23e81a520;
                    plVar16 = (longlong *)PyNumber_Long(plVar15[2]);
                    if (plVar16 == (longlong *)0x0) {
                      local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      plVar13 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar26 = 0x1f5;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pcVar23 = (code *)0x0;
                      plVar17 = DAT_23ed6a4f8;
                      local_138 = pcVar25;
                    }
                    else {
                      if ((local_e8 != (longlong *)0x0) &&
                         (lVar12 = *local_e8, *local_e8 = lVar12 + -1, lVar12 + -1 == 0)) {
                        FUN_23a334bc0(local_e8);
                      }
                      plVar18 = (longlong *)PyNumber_Long(plVar18);
                      local_e8 = plVar16;
                      if (plVar18 != (longlong *)0x0) {
                        if ((local_d8 != (longlong *)0x0) &&
                           (lVar12 = *local_d8, *local_d8 = lVar12 + -1, lVar12 + -1 == 0)) {
                          FUN_23a334bc0(local_d8);
                        }
LAB_23e81b02f:
                        plVar16 = (longlong *)FUN_23e8d09c0(local_e8,plVar18);
                        local_d8 = plVar18;
                        if (plVar16 == (longlong *)0x0) {
                          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                          plVar13 = *(longlong **)(param_1 + 0x70);
                          uVar26 = 0x1f7;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          pcVar23 = (code *)0x0;
                          plVar17 = DAT_23ed6a4f8;
                          local_138 = pcVar25;
                          goto joined_r0x00023e819693;
                        }
                        iVar10 = FUN_23a35f020(plVar16);
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          FUN_23a334bc0(plVar16);
                        }
                        if (iVar10 == -1) {
                          local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                          local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                          plVar13 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          goto LAB_23e81c552;
                        }
                        if (iVar10 != 0) {
                          uVar22 = FUN_23a3a0d40(DAT_23eedd4c0);
                          lVar12 = *(longlong *)(DAT_23eedd0f0 + 0x20);
                          if (*(char *)(lVar12 + 10) == '\0') {
                            plVar16 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,DAT_23eedd6d8);
                            if (plVar16 == (longlong *)0x0) goto LAB_23e81c33e;
                            lVar12 = *plVar16;
LAB_23e81c335:
                            if (lVar12 == 0) goto LAB_23e81c33e;
                          }
                          else {
                            iVar10 = *(int *)(lVar12 + 0xc);
                            if (*(int *)(lVar12 + 0xc) == 0) {
                              *(int *)(lVar12 + 0xc) = DAT_23ec155d8;
                              iVar10 = DAT_23ec155d8;
                              DAT_23ec155d8 = DAT_23ec155d8 + 1;
                            }
                            if (DAT_23ec15598 != iVar10) {
                              DAT_23ec15598 = iVar10;
                              DAT_23eede7f8 =
                                   FUN_23e8cbd60(lVar12,DAT_23eedd6d8,
                                                 *(undefined8 *)(DAT_23eedd6d8 + 0x18));
                            }
                            if (-1 < DAT_23eede7f8) {
                              lVar4 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                              if (*(longlong *)(lVar4 + 8 + DAT_23eede7f8 * 0x10) != 0)
                              goto LAB_23e81b10c;
                              DAT_23eede7f8 =
                                   FUN_23e8cbd60(lVar12,DAT_23eedd6d8,
                                                 *(undefined8 *)(DAT_23eedd6d8 + 0x18));
                              if (-1 < DAT_23eede7f8) {
                                lVar12 = *(longlong *)(lVar4 + 8 + DAT_23eede7f8 * 0x10);
                                goto LAB_23e81c335;
                              }
                            }
LAB_23e81c33e:
                            plVar16 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedd6d8);
                            if ((plVar16 == (longlong *)0x0) || (*plVar16 == 0)) {
                              pcVar23 = (code *)0x0;
                              FUN_23e915740(param_1,local_98,DAT_23eedd6d8);
                              uVar26 = 0x1f8;
                              plVar17 = DAT_23ed6a4f8;
                              local_138 = pcVar25;
                              plVar13 = local_88[0];
                              goto joined_r0x00023e819693;
                            }
                          }
LAB_23e81b10c:
                          plVar16 = (longlong *)FUN_23e8c09e0();
                          if (plVar16 == (longlong *)0x0) {
                            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            plVar13 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e81ca74:
                            pcVar23 = (code *)0x0;
                            uVar26 = 0x1f8;
                            plVar17 = DAT_23ed6a4f8;
                            local_138 = pcVar25;
                          }
                          else {
                            *(undefined4 *)(plVar11 + 5) = 0x1f8;
                            local_78 = plVar16;
                            plStack_70 = plVar18;
                            plVar19 = (longlong *)FUN_23e94ed00(param_1,uVar22);
                            *plVar16 = *plVar16 + -1;
                            if (*plVar16 == 0) {
                              FUN_23a334bc0(plVar16);
                            }
                            if (plVar19 == (longlong *)0x0) {
                              plVar13 = *(longlong **)(param_1 + 0x70);
                              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              goto LAB_23e81ca74;
                            }
                            if ((local_e0 != (longlong *)0x0) &&
                               (*local_e0 = *local_e0 + -1, *local_e0 == 0)) {
                              FUN_23a334bc0(local_e0);
                            }
                            plVar16 = (longlong *)FUN_23e8c6640(plVar19,local_e8);
                            local_e0 = plVar19;
                            if (plVar16 == (longlong *)0x0) {
                              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                              plVar13 = *(longlong **)(param_1 + 0x70);
                              uVar26 = 0x1f9;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              pcVar23 = (code *)0x0;
                              plVar17 = DAT_23ed6a4f8;
                              local_138 = pcVar25;
                            }
                            else {
                              iVar10 = FUN_23e97d380(plVar16,DAT_23eedd578);
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                FUN_23a334bc0();
                              }
                              if (iVar10 == -1) {
                                local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                plVar13 = *(longlong **)(param_1 + 0x70);
                                uVar26 = 0x1f9;
                                pcVar23 = (code *)0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plVar17 = DAT_23ed6a4f8;
                                local_138 = pcVar25;
                              }
                              else {
                                if (iVar10 != 1) goto LAB_23e81b1c5;
                                plVar16 = (longlong *)FUN_23e8bc2f0(plVar21,DAT_23eedd2d0);
                                if (plVar16 == (longlong *)0x0) {
                                  plVar13 = *(longlong **)(param_1 + 0x70);
                                  local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                  local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                }
                                else {
                                  plVar20 = (longlong *)
                                            FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                                  *local_e8 = *local_e8 + 1;
                                  plVar20[3] = (longlong)local_e8;
                                  *plVar19 = *plVar19 + 1;
                                  plVar20[4] = (longlong)plVar19;
                                  *(undefined4 *)(plVar11 + 5) = 0x1fa;
                                  plVar24 = (longlong *)FUN_23e914090(param_1,plVar16);
                                  *plVar16 = *plVar16 + -1;
                                  if (*plVar16 == 0) {
                                    FUN_23a334bc0(plVar16);
                                  }
                                  *plVar20 = *plVar20 + -1;
                                  if (*plVar20 == 0) {
                                    FUN_23a334bc0(plVar20);
                                  }
                                  if (plVar24 != (longlong *)0x0) {
                                    *plVar24 = *plVar24 + -1;
                                    if (*plVar24 == 0) {
                                      FUN_23a334bc0(plVar24);
                                    }
                                    goto LAB_23e81b1c5;
                                  }
                                  local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                  local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                  plVar13 = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                }
                                pcVar23 = (code *)0x0;
                                uVar26 = 0x1fa;
                                plVar17 = DAT_23ed6a4f8;
                                local_138 = pcVar25;
                              }
                            }
                          }
                          goto joined_r0x00023e819693;
                        }
                        goto LAB_23e81a520;
                      }
                      local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      plVar13 = *(longlong **)(param_1 + 0x70);
                      uVar26 = 0x1f6;
                      pcVar23 = (code *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar17 = DAT_23ed6a4f8;
                      local_138 = pcVar25;
                    }
                  }
                }
                goto joined_r0x00023e819693;
              }
              plVar13 = *(longlong **)(param_1 + 0x70);
              local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
              local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            pcVar23 = (code *)0x0;
            uVar26 = 499;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            goto joined_r0x00023e819693;
          }
LAB_23e81a520:
          plVar16 = (longlong *)FUN_23e8c09e0(plVar15[2],plVar13);
          if (plVar16 == (longlong *)0x0) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar26 = 0x1fc;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar23 = (code *)0x0;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            goto joined_r0x00023e819693;
          }
          if ((local_100 != (longlong *)0x0) &&
             (lVar12 = *local_100, *local_100 = lVar12 + -1, lVar12 + -1 == 0)) {
            (**(code **)(local_100[1] + 0x30))(local_100);
          }
          iVar10 = FUN_23e97b4b0(plVar16,local_108);
          local_100 = plVar16;
          if (iVar10 == -1) {
            local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            uVar26 = 0x1fd;
            pcVar23 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar17 = DAT_23ed6a4f8;
            local_138 = pcVar25;
            goto joined_r0x00023e819693;
          }
          if (iVar10 == 1) goto LAB_23e81b7a8;
          *plVar16 = *plVar16 + 1;
          lVar12 = *local_108;
          *local_108 = lVar12 + -1;
          if (lVar12 + -1 == 0) {
            (**(code **)(local_108[1] + 0x30))(local_108);
          }
          lVar12 = *(longlong *)(param_1 + 0x10);
          local_108 = plVar16;
          if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) != 0) ||
               (*(int *)(lVar12 + 0x78) != 0)) && (iVar10 = Py_MakePendingCalls(), iVar10 < 0)) &&
             (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e81a9a7;
          if (*(int *)(lVar12 + 0x68) == 0) {
            plVar13 = *(longlong **)(param_1 + 0x90);
          }
          else {
            PyEval_SaveThread();
            PyEval_AcquireThread(param_1);
            plVar13 = *(longlong **)(param_1 + 0x90);
          }
        } while (plVar13 == (longlong *)0x0);
        plVar17 = *(longlong **)(param_1 + 0x60);
        plVar16 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar13;
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar18 = *(longlong **)(param_1 + 0x68);
        *plVar13 = *plVar13 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
          (**(code **)(plVar17[1] + 0x30))();
        }
        if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
          (**(code **)(plVar18[1] + 0x30))(plVar18);
        }
        if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
LAB_23e81a9a7:
        local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        plVar13 = *(longlong **)(param_1 + 0x70);
        uVar26 = 0x1e4;
        pcVar23 = (code *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar17 = DAT_23ed6a4f8;
        local_138 = pcVar25;
      }
      goto joined_r0x00023e819693;
    }
    local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    local_88[0] = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar12 = *plVar14;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar14 = lVar12 + -1;
    if (lVar12 + -1 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  plVar14 = (longlong *)0x0;
  local_100 = (longlong *)0x0;
  pcVar23 = (code *)0x0;
  plVar21 = (longlong *)0x0;
  uVar26 = 0x1dc;
  local_e0 = (longlong *)0x0;
  local_d8 = (longlong *)0x0;
  local_e8 = (longlong *)0x0;
  local_f0 = (longlong *)0x0;
  local_f8 = (longlong *)0x0;
  local_c8 = (longlong *)0x0;
  local_d0 = (longlong *)0x0;
  local_110 = (longlong *)0x0;
  local_108 = (longlong *)0x0;
  local_138 = (code *)0x0;
  plVar17 = DAT_23ed6a4f8;
  plVar13 = local_88[0];
joined_r0x00023e819693:
  DAT_23ed6a4f8 = plVar17;
  local_88[0] = plVar13;
  if (plVar13 == (longlong *)0x0) {
    if (plVar17 == (longlong *)0x0) {
      plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar17;
      *plVar17 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar25 = _PyRuntime_exref;
    plVar17[3] = (longlong)plVar11;
    plVar17[2] = 0;
    *plVar11 = *plVar11 + 1;
    lVar12 = *(longlong *)(pcVar25 + 0x1f8);
    *(undefined4 *)((longlong)plVar17 + 0x24) = uVar26;
    *(undefined4 *)(plVar17 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar4 = plVar17[-1];
    puVar5 = *(undefined8 **)(lVar12 + 8);
    *puVar5 = plVar17 + -2;
    plVar17[-2] = lVar12;
    plVar17[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar12 + 8) = plVar17 + -2;
    plVar13 = plVar17;
    if ((local_88[0] != (longlong *)0x0) && (*local_88[0] = *local_88[0] + -1, *local_88[0] == 0)) {
      (**(code **)(local_88[0][1] + 0x30))(local_88[0]);
    }
  }
  else if ((longlong *)plVar13[3] != plVar11) {
    if (plVar17 == (longlong *)0x0) {
      plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar17;
      *plVar17 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar25 = _PyRuntime_exref;
    plVar17[3] = (longlong)plVar11;
    *plVar11 = *plVar11 + 1;
    lVar12 = *(longlong *)(pcVar25 + 0x1f8);
    *(undefined4 *)((longlong)plVar17 + 0x24) = uVar26;
    *(undefined4 *)(plVar17 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar4 = plVar17[-1];
    puVar5 = *(undefined8 **)(lVar12 + 8);
    *puVar5 = plVar17 + -2;
    plVar17[-2] = lVar12;
    plVar17[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar12 + 8) = plVar17 + -2;
    plVar17[2] = (longlong)plVar13;
    *plVar13 = *plVar13 + 1;
    plVar13 = plVar17;
    if ((local_88[0] != (longlong *)0x0) && (*local_88[0] = *local_88[0] + -1, *local_88[0] == 0)) {
      (**(code **)(local_88[0][1] + 0x30))(local_88[0]);
    }
  }
  local_88[0] = plVar13;
  FUN_23e8bba40(plVar11,"oooooooooocooooooo",plVar1,plVar2,plVar3,plVar14,local_138,plVar21,
                local_108,local_110,local_d0,local_c8,plVar15,local_f8,local_f0,local_e8,local_d8,
                local_e0,local_100,pcVar23);
  if (DAT_23eede800 == plVar11) {
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    DAT_23eede800 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar12 + 0x28);
  plVar13 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar13 = local_88[0];
  uVar7 = local_98._8_8_;
  uVar22 = local_98._0_8_;
  plVar11[0xf] = 0;
  local_98 = (undefined1  [16])0x0;
  local_88[0] = (longlong *)0x0;
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((local_138 != (code *)0x0) &&
     (lVar12 = *(longlong *)local_138, *(longlong *)local_138 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(*(longlong *)(local_138 + 8) + 0x30))(local_138);
  }
  if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
    (**(code **)(plVar21[1] + 0x30))(plVar21);
  }
  if ((local_108 != (longlong *)0x0) &&
     (lVar12 = *local_108, *local_108 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_108[1] + 0x30))(local_108);
  }
  if ((local_110 != (longlong *)0x0) &&
     (lVar12 = *local_110, *local_110 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_110[1] + 0x30))(local_110);
  }
  if ((local_d0 != (longlong *)0x0) &&
     (lVar12 = *local_d0, *local_d0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_d0[1] + 0x30))();
  }
  if ((local_c8 != (longlong *)0x0) &&
     (lVar12 = *local_c8, *local_c8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_c8[1] + 0x30))(local_c8);
  }
  *plVar15 = *plVar15 + -1;
  if (*plVar15 == 0) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if ((local_f8 != (longlong *)0x0) &&
     (lVar12 = *local_f8, *local_f8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_f8[1] + 0x30))(local_f8);
  }
  if ((local_f0 != (longlong *)0x0) &&
     (lVar12 = *local_f0, *local_f0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_f0[1] + 0x30))(local_f0);
  }
  if ((local_e8 != (longlong *)0x0) &&
     (lVar12 = *local_e8, *local_e8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_e8[1] + 0x30))(local_e8);
  }
  if ((local_d8 != (longlong *)0x0) &&
     (lVar12 = *local_d8, *local_d8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_d8[1] + 0x30))(local_d8);
  }
  if ((local_e0 != (longlong *)0x0) &&
     (lVar12 = *local_e0, *local_e0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_e0[1] + 0x30))(local_e0);
  }
  if ((local_100 != (longlong *)0x0) &&
     (lVar12 = *local_100, *local_100 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_100[1] + 0x30))(local_100);
  }
  if ((pcVar23 != (code *)0x0) &&
     (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 == 0)) {
    (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
  }
  local_98 = CONCAT88(uVar7,uVar22);
  lVar12 = *plVar1;
  *plVar1 = lVar12 + -1;
  local_88[0] = plVar13;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar12 = *plVar2;
  *plVar2 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar12 = *plVar3;
  *plVar3 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,local_98._0_8_,local_98._8_8_,local_88[0]);
  return (code *)0x0;
LAB_23e81b1c5:
  *plVar19 = *plVar19 + 1;
  *local_e8 = *local_e8 + -1;
  if (*local_e8 == 0) {
    FUN_23a334bc0(local_e8);
  }
  cVar9 = FUN_23a3a5fe0(param_1);
  local_e8 = plVar19;
  if (cVar9 == '\0') {
    plVar13 = *(longlong **)(param_1 + 0x70);
    local_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    local_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e81c552:
    uVar26 = 0x1f7;
    pcVar23 = (code *)0x0;
    plVar17 = DAT_23ed6a4f8;
    local_138 = pcVar25;
    goto joined_r0x00023e819693;
  }
  goto LAB_23e81b02f;
}
